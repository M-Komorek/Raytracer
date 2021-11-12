#include <gtest/gtest.h>

#include "TestUtils.hpp"

#include "shape/Sphere.hpp"

TEST(SphereShould, returnNoneWhileHittedByRayAndDeltaIsNegative)
{
    const rt::core::Point3 origin{1,2,3};
    const rt::core::Vector3 direction{2,2,2};
    const rt::core::Ray ray{origin, direction};

    const rt::shape::Sphere sphere{nullptr, rt::core::Point3(0,0,0), 1};

    const auto timeOfHit = sphere.gotHittedByRay(ray, 1, 10);

    EXPECT_EQ(std::optional<double>(), timeOfHit);
}

TEST(SphereShould, returnNoneWhileHittedByRayButOverTimeLimit)
{
    const rt::core::Point3 origin{0,0,1};
    const rt::core::Vector3 direction{2,2,2};
    const rt::core::Ray ray{origin, direction};

    const rt::shape::Sphere sphere{nullptr, rt::core::Point3(0,0,1), 1};

    const auto timeOfHit = sphere.gotHittedByRay(ray, 1, 10);

    EXPECT_EQ(std::optional<double>(), timeOfHit);
}

TEST(SphereShould, returnTimeWhileHittedByRayInTimeLimitNegativeRoot)
{
    const rt::core::Point3 origin{0,0,1};
    const rt::core::Vector3 direction{2,2,2};
    const rt::core::Ray ray{origin, direction};

    const rt::shape::Sphere sphere{nullptr, rt::core::Point3(0,0,1), 1};

    const auto timeOfHit = sphere.gotHittedByRay(ray, -1, 10);

    EXPECT_NEAR(std::optional<double>(-0.288675).value(), timeOfHit.value(), 0.000001);
}

TEST(SphereShould, returnTimeWhileHittedByRayInTimeLimitPositiveRoot)
{
    const rt::core::Point3 origin{0,0,1};
    const rt::core::Vector3 direction{2,2,2};
    const rt::core::Ray ray{origin, direction};

    const rt::shape::Sphere sphere{nullptr, rt::core::Point3(0,0,1), 1};

    const auto timeOfHit = sphere.gotHittedByRay(ray, 0, 10);

    EXPECT_NEAR(std::optional<double>(0.288675).value(), timeOfHit.value(), 0.000001);
}

TEST(SphereShould, calculateHitRecord)
{
    const rt::core::Point3 origin{1,2,3};
    const rt::core::Vector3 direction{2,2,2};
    const rt::core::Ray ray{origin, direction};

    const rt::shape::Sphere sphere{nullptr, rt::core::Point3(0,0,0), 1};

    const auto hitRecord = sphere.calculateHitRecord(ray, 1);

    EXPECT_EQ(1, hitRecord.t);
    testUtils::isEqual<rt::core::Point3>(rt::core::Point3(3,4,5), hitRecord.borderPoint);
    EXPECT_EQ(false, hitRecord.frontFace);
    testUtils::isEqual<rt::core::Vector3>(rt::core::Vector3(-3,-4,-5), hitRecord.normal);
}