#include <gtest/gtest.h>

#include "TestUtils.hpp"

#include "core/Ray.hpp"

TEST(RayShould, createWithGivenOriginAndDirection)
{
    const rt::core::Point3 origin{1,2,3};
    const rt::core::Vector3 direction{4,5,6};
    const rt::core::Ray ray{origin, direction};

    testUtils::isEqual<rt::core::Point3>(ray.getOrigin(), origin);
    testUtils::isEqual<rt::core::Vector3>(ray.getDirection(), direction);
}

TEST(RayShould, setGivenOrigin)
{
    const rt::core::Point3 origin{1,2,3};
    const rt::core::Vector3 direction{4,5,6};
    rt::core::Ray ray{origin, direction};

    const rt::core::Point3 newOrigin{10.0, 10.0, 10.0};
    ray.setOrigin(newOrigin);

    testUtils::isEqual<rt::core::Point3>(newOrigin, ray.getOrigin());
}

TEST(RayShould, setGivenDirection)
{
    const rt::core::Point3 origin{1,2,3};
    const rt::core::Vector3 direction{4,5,6};
    rt::core::Ray ray{origin, direction};

    const rt::core::Vector3 newDirection{10.0, 10.0, 10.0};
    ray.setDirection(newDirection);

    testUtils::isEqual<rt::core::Vector3>(newDirection, ray.getDirection());
}

TEST(RayShould, calculateAt)
{
    const rt::core::Point3 origin{1,2,3};
    const rt::core::Vector3 direction{4,5,6};
    rt::core::Ray ray{origin, direction};

    const rt::core::Point3 expectedPoint{5, 7, 9};
    const rt::core::Point3 pointAtT = ray.at(1.0);

    testUtils::isEqual<rt::core::Point3>(expectedPoint, pointAtT);
}

TEST(RayShould, bePrintable)
{
    const rt::core::Point3 origin{1,2,3};
    const rt::core::Vector3 direction{4,5,6};
    const rt::core::Ray ray{origin, direction};

    const auto result = ray.toString();

    const std::string expectedResult = "Origin: (1.000000, 2.000000, 3.000000)"
                                       " Direction: [4.000000, 5.000000, 6.000000]";

    EXPECT_EQ(expectedResult, result);
}
