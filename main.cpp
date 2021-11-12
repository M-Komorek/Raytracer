#include <iostream>
#include <cmath>

#include "core/Vector3.hpp"
#include "core/Color.hpp"
#include "core/Ray.hpp"
#include "core/Utils.hpp"

#include "shape/base/HittableList.hpp"
#include "shape/Sphere.hpp"
#include "shape/base/HitRecord.hpp"
#include "shape/material/IMaterial.hpp"
#include "shape/material/Matte.hpp"
#include "shape/material/Metal.hpp"

#include "scene/Camera.hpp"

// Temporary - to refactor
// It should be hidden by some kind of abstraction
rt::core::Color rayColor(
    const rt::core::Ray& ray, const rt::shape::base::HittableList& world, const int depth)
{
    std::optional<rt::shape::base::HitRecord> hitRecord = world.getClosestHitRecord(
        ray, 0.001, std::numeric_limits<double>::infinity());
    
    if (depth <= 0)
        return rt::core::Color();

    if(hitRecord)
    {
        const auto scatterRay = hitRecord.value().material->procudeScatterRay(ray, hitRecord.value());
        if (scatterRay)
            return hitRecord.value().material->getReflectedLight() * rayColor(scatterRay.value(), world, depth-1);
        return rt::core::Color(0,0,0);
    }

    auto rayDirection(ray.getDirection());
    rayDirection.normalize();
    const auto t = 0.5*(rayDirection.y() + 1.0);
    return rt::core::Color(1.0, 1.0, 1.0)*(1.0-t) + rt::core::Color(0.5, 0.7, 1.0)*t;
}

int main()
{
    // Image
    const auto imageRatio = 16.0 / 9.0;
    const int imageWidth = 1200;
    const int imageHeight = static_cast<int>(imageWidth/imageRatio);
    const int samplesPerPixel = 100;
    int maxDepth = 50;

    // World
    rt::shape::base::HittableList world;

    const auto groundMaterial = std::make_shared<rt::shape::material::Matte>(rt::core::Color(0.80, 0.80, 0.80));
    const auto rightMaterial1 = std::make_shared<rt::shape::material::Matte>(rt::core::Color(0.70, 0.30, 0.30));
    const auto rightMaterial2 = std::make_shared<rt::shape::material::Matte>(rt::core::Color(0.10, 0.10, 0.60));
    const auto leftMaterial1  = std::make_shared<rt::shape::material::Metal>(rt::core::Color(0.66, 0.66, 0.66), 0.5);
    const auto leftMaterial2  = std::make_shared<rt::shape::material::Metal>(rt::core::Color(0.41, 0.41, 0.41), 1.0);

    world.add(std::make_unique<rt::shape::Sphere>(groundMaterial, rt::core::Point3( 0.00, -100.5, -1.00),  100));
    world.add(std::make_unique<rt::shape::Sphere>(rightMaterial1, rt::core::Point3( 1.10,      0, -1.45), 0.5));
    world.add(std::make_unique<rt::shape::Sphere>(rightMaterial2, rt::core::Point3( 1.10,   -0.4, -0.90),  0.1));
    world.add(std::make_unique<rt::shape::Sphere>(leftMaterial1,  rt::core::Point3(-0.95,      0, -1.35), 0.5));
    world.add(std::make_unique<rt::shape::Sphere>(leftMaterial2,  rt::core::Point3( 0.00,      0, -2.55), 0.5));
    // Camera
    rt::scene::Camera camera{};

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
                auto u = static_cast<double>(i + rt::core::randomDouble()) / (imageWidth-1);
                auto v = static_cast<double>(j + rt::core::randomDouble()) / (imageHeight-1);

                rt::core::Ray ray = camera.getRay(u, v);
                pixelColor += rayColor(ray, world, maxDepth-1);
                
            }
            pixelColor.serializeToStream(samplesPerPixel);
        }
    }

    std::cerr << "\nDone.\n";
}
