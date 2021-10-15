#include <gtest/gtest.h>

#include "TestUtils.hpp"

#include "shape/base/HitRecord.hpp"

TEST(HitRecordShould, setFrontFaceAndNormalWhenRayIsInsideTheObject)
{
    const rt::core::Point3 origin{1,2,3};
    const rt::core::Vector3 direction{2,2,2};
    const rt::core::Ray ray{origin, direction};

    rt::shape::base::HitRecord hitRecord;
    const rt::core::Vector3 normal{2,2,2};
    hitRecord.setFrontFaceAndNormal(ray, normal);

    const rt::core::Vector3 expectedNormal = direction*(-1);

    EXPECT_EQ(false, hitRecord.frontFace);
    testUtils::isEqual<rt::core::Vector3>(expectedNormal, hitRecord.normal);
}

TEST(HitRecordShould, setFrontFaceAndNormalWhenRayIsOutInsideTheObject)
{
    const rt::core::Point3 origin{1,2,3};
    const rt::core::Vector3 direction{2,2,2};
    const rt::core::Ray ray{origin, direction};

    rt::shape::base::HitRecord hitRecord;
    const rt::core::Vector3 normal{2,-2,-2};
    hitRecord.setFrontFaceAndNormal(ray, normal);

    EXPECT_EQ(true, hitRecord.frontFace);
    testUtils::isEqual<rt::core::Vector3>(normal, hitRecord.normal);
}