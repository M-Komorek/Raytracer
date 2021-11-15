#include <gtest/gtest.h>

#include "TestUtils.hpp"

#include "scene/OrthonormalBasis.hpp"
#include "scene/View.hpp"

#include "scene/Camera.hpp"


TEST(CameraShould, calculateRays)
{
    const auto imageRatio = 16.0 / 9.0;
    const auto scenePortHeight = 2.0;
    const auto scenePortWidth = imageRatio * scenePortHeight;
    
    const auto origin = rt::core::Point3();
    
    const auto horizontalSpanOfTheScene = rt::core::Vector3(scenePortWidth, 0, 0);
    const auto verticalSpanOfTheScene = rt::core::Vector3(0, scenePortHeight, 0);
    const auto lowerLeftCornerOfTheScene = origin - horizontalSpanOfTheScene/2 - verticalSpanOfTheScene/2 - rt::core::Vector3(0, 0, 1);
    const rt::scene::View view{lowerLeftCornerOfTheScene, horizontalSpanOfTheScene, verticalSpanOfTheScene};

    const rt::scene::Camera camera{origin, rt::scene::OrthonormalBasis{}, view};

    const auto ray = camera.getRay(10, 10);

    testUtils::isEqual<rt::core::Point3>(rt::core::Point3(), ray.getOrigin());
    testUtils::isEqual<rt::core::Vector3>(rt::core::Vector3(32, 18, -1), ray.getDirection());
}
