#include <gtest/gtest.h>

#include "TestUtils.hpp"

#include "scene/Camera.hpp"


TEST(CameraShould, calculateRays)
{
    const rt::scene::Camera camera{};

    const auto ray = camera.getRay(10, 10);

    testUtils::isEqual<rt::core::Point3>(rt::core::Point3(), ray.getOrigin());
    testUtils::isEqual<rt::core::Vector3>(rt::core::Vector3(32, 18, -1), ray.getDirection());
}
