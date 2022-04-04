#include <iostream>
#include <cmath>
#include <chrono>
#include <future>

#include "core/Vector3.hpp"
#include "core/Color.hpp"
#include "core/Ray.hpp"
#include "core/Utils.hpp"

#include "scene/Camera.hpp"

#include "shape/base/HittableList.hpp"
#include "shape/Sphere.hpp"
#include "shape/base/HitRecord.hpp"
#include "shape/material/IMaterial.hpp"
#include "shape/material/Matte.hpp"
#include "shape/material/Metal.hpp"

void renderTheFragment(const int startW, const int endW,
    const int startH, const int endH,
    const int imageW, const int imageH,
    const int samplesPerPixel,
    int maxDepth,
    const rt::scene::Camera& camera,
    const rt::shape::base::HittableList& world,
    std::vector<std::vector<rt::core::Color>>& image)
{
    std::cerr << "Start rendering on separated thread...\n" << std::flush;
    for (int i = startH; i<endH; ++i)
    {
        for (int j = startW; j<endW; ++j)
        {
            rt::core::Color pixelColor;

            for (int s = 0; s<samplesPerPixel; ++s)
            {
                auto horizontalOffset = static_cast<double>(j + rt::core::randomDouble()) / (imageW-1);
                auto verticalOffset   = static_cast<double>(i + rt::core::randomDouble()) / (imageH-1);

                const auto ray = camera.getRay(horizontalOffset, verticalOffset);
                pixelColor += camera.getRayColor(ray, world, maxDepth-1);
                
            }

            image[i][j] = pixelColor;
        }
    }
}

void multithreadedRender(const int threadsNumber,
    const int imageWidth, const int imageHeight,
    const int samplesPerPixel,
    const int maxDepth,
    const rt::scene::Camera& camera,
    const rt::shape::base::HittableList& world,
    std::vector<std::vector<rt::core::Color>>& image)
{
    std::vector<std::future<void>> futures{};
    futures.reserve(threadsNumber);

    futures.emplace_back(std::async(std::launch::async, renderTheFragment,
        0, imageWidth,
        0, imageHeight/threadsNumber,
        imageWidth, imageHeight,
        samplesPerPixel,
        maxDepth,
        std::ref(camera),
        std::ref(world),
        std::ref(image)));

    for (int i=1; i<threadsNumber; ++i)
    {
        futures.emplace_back(std::async(std::launch::async, renderTheFragment,
            0, imageWidth,
            imageHeight/threadsNumber * i, imageHeight/threadsNumber * (i+1),
            imageWidth, imageHeight,
            samplesPerPixel,
            maxDepth,
            std::ref(camera),
            std::ref(world),
            std::ref(image)));
    }

    for (const auto& f : futures)
    {
        f.wait();
    }
}

int main()
{
    const auto numberOfThreads = 4;

    // Image
    const auto imageRatio = 3.0 / 2.0;
    const int imageWidth = 400;
    const int imageHeight = static_cast<int>(imageWidth/imageRatio);
    const int samplesPerPixel = 50;
    int maxDepth = 20;

    std::vector<std::vector<rt::core::Color>> image(imageHeight, std::vector<rt::core::Color>(imageWidth));

    // World
    rt::shape::base::HittableList world;

    const auto ground = std::make_shared<rt::shape::material::Matte>(rt::core::Color(0.1, 0.1, 0.1));
    world.add(std::make_unique<rt::shape::Sphere>(ground, rt::core::Point3(  0.0, -1000, 0), 1000));

    const auto silver  = std::make_shared<rt::shape::material::Metal>(rt::core::Color(0.7000, 0.6000, 0.5000), 0.0);
    const auto gold   = std::make_shared<rt::shape::material::Metal>(rt::core::Color(0.8281, 0.6836, 0.2148), 0.0);
    const auto blue = std::make_shared<rt::shape::material::Matte>(rt::core::Color(0.2859, 0.6210, 0.8008));
    const auto smallMetal = std::make_shared<rt::shape::material::Metal>(rt::core::Color(0.5859, 0.0000, 0.8008), 0.3);

    world.add(std::make_unique<rt::shape::Sphere>(silver,  rt::core::Point3(  1.1,  0.5, -1.0), 0.5));
    world.add(std::make_unique<rt::shape::Sphere>(gold,   rt::core::Point3( -1.1,  0.5, -1.0), 0.5));

    world.add(std::make_unique<rt::shape::Sphere>(blue, rt::core::Point3(  0.0,  0.35, -1.0), 0.35));
    world.add(std::make_unique<rt::shape::Sphere>(blue, rt::core::Point3(  0.60, 0.30,  0.15), 0.30));

    world.add(std::make_unique<rt::shape::Sphere>(smallMetal, rt::core::Point3(  0.05, 0.15, -0.40), 0.15));
    world.add(std::make_unique<rt::shape::Sphere>(smallMetal, rt::core::Point3(  0.50, 0.15, -0.30), 0.15));
    world.add(std::make_unique<rt::shape::Sphere>(smallMetal, rt::core::Point3( -0.20, 0.15,  0.45), 0.15));
    world.add(std::make_unique<rt::shape::Sphere>(smallMetal, rt::core::Point3( -0.60, 0.15, -0.20), 0.15));

    // Camera
    const auto camera = rt::scene::Camera::create(
        rt::core::Point3(-2,1.75,1), rt::core::Point3(0,0,-1), 45, imageRatio, 0.0);

    
    std::cerr << "Number of threas: " << numberOfThreads << '\n';

    // Render
    const auto start = std::chrono::steady_clock::now();

    multithreadedRender(numberOfThreads, imageWidth, imageHeight, samplesPerPixel, maxDepth,
        std::ref(camera), std::ref(world), std::ref(image));

    const auto end = std::chrono::steady_clock::now();

    std::cerr << "Elapsed time in milliseconds: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
            << " ms\n";
    

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";
    for (int i=imageHeight-1; i>=0; --i)
    {
        for (int j=0; j<imageWidth; ++j)
        {
            image[i][j].serializeToStream(samplesPerPixel);
        }
    }

    std::cerr << "\nDone.\n";
}
