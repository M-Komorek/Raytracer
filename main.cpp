#include <iostream>
#include <cmath>

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

int main()
{
    // Image
    const auto imageRatio = 16.0 / 9.0;
    const int imageWidth = 400;
    const int imageHeight = static_cast<int>(imageWidth/imageRatio);
    const int samplesPerPixel = 100;
    int maxDepth = 50;

    // World
    rt::shape::base::HittableList world;

    const auto ground = std::make_shared<rt::shape::material::Matte>(rt::core::Color(0.8, 0.8, 0.0));
    const auto left   = std::make_shared<rt::shape::material::Matte>(rt::core::Color(0.1, 0.2, 0.5));
    const auto right  = std::make_shared<rt::shape::material::Metal>(rt::core::Color(0.8, 0.6, 0.2), 0.0);

    world.add(std::make_unique<rt::shape::Sphere>(ground, rt::core::Point3( -0.0, -100.5, -1.0), 100));
    world.add(std::make_unique<rt::shape::Sphere>(left,   rt::core::Point3(  0.0,    0.0, -1.0), 0.5));
    world.add(std::make_unique<rt::shape::Sphere>(right,  rt::core::Point3(  1.0,    0.0, -1.0), 0.5));

    // Camera
    const auto camera = rt::scene::Camera::create(
        rt::core::Point3(-2,2,1), rt::core::Point3(0,0,-1), 30, imageRatio);

    // Render
    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";
    for (int j = imageHeight-1; j>=0; --j)
    {
        std::cerr << "\r[" << static_cast<int>((imageHeight-j)*100/imageHeight) << "%] Rendering..." << std::flush;
        for (int i = 0; i<imageWidth; ++i)
        {
            rt::core::Color pixelColor;

            for (int s = 0; s<samplesPerPixel; ++s)
            {
                auto horizontalOffset = static_cast<double>(i + rt::core::randomDouble()) / (imageWidth-1);
                auto verticalOffset   = static_cast<double>(j + rt::core::randomDouble()) / (imageHeight-1);

                const auto ray = camera.getRay(horizontalOffset, verticalOffset);
                pixelColor += camera.getRayColor(ray, world, maxDepth-1);
                
            }
            pixelColor.serializeToStream(samplesPerPixel);
        }
    }

    std::cerr << "\nDone.\n";
}
