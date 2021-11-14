#include <gtest/gtest.h>

#include "TestUtils.hpp"

#include "scene/Camera.hpp"


TEST(CameraShould, calculateRays)
{
    const auto imageRatio = 16.0 / 9.0;
    const auto scenePortHeight = 2.0;
    const auto scenePortWidth = imageRatio * scenePortHeight;
    
    const auto origin = rt::core::Point3();
    const auto horizontal = rt::core::Vector3(scenePortWidth, 0, 0);
    const auto vertical = rt::core::Vector3(0, scenePortHeight, 0);
    const auto lowerLeftCorner = origin - horizontal/2 - vertical/2 - rt::core::Vector3(0, 0, 1);

    const rt::scene::Camera camera{origin, lowerLeftCorner, horizontal, vertical};

    const auto ray = camera.getRay(10, 10);

    testUtils::isEqual<rt::core::Point3>(rt::core::Point3(), ray.getOrigin());
    testUtils::isEqual<rt::core::Vector3>(rt::core::Vector3(32, 18, -1), ray.getDirection());
}
