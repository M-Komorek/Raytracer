#include <gtest/gtest.h>

#include "shape/base/HittableList.hpp"
#include "shape/Sphere.hpp"

TEST(HittableListShould, returnNoneWhenThereAreNoShapes)
{
    const rt::core::Point3 origin{};
    const rt::core::Vector3 direction{};
    const rt::core::Ray ray{origin, direction};

    rt::shape::base::HittableList hittableList{};
    const auto result = hittableList.getClosestHitRecord(ray, 0, 10);

    EXPECT_FALSE(result);
}

TEST(HittableListShould, returnClosestHitRecordWhenThereAreShapes)
{
    const rt::core::Point3 origin{0,0,1};
    const rt::core::Vector3 direction{2,2,2};
    const rt::core::Ray ray{origin, direction};

    rt::shape::base::HittableList hittableList{};
    hittableList.add(std::make_unique<rt::shape::Sphere>(rt::core::Point3(0,0,1), 1));
    hittableList.add(std::make_unique<rt::shape::Sphere>(rt::core::Point3(0,0,1), 2));
    const auto result1 = hittableList.getClosestHitRecord(ray, 0, 10);
    const auto result2 = hittableList.getClosestHitRecord(ray, -10, 10);

    EXPECT_NEAR( 0.288675, result1.value().t, 0.000001);
    EXPECT_NEAR(-0.577350, result2.value().t, 0.000001);
}

TEST(HittableListShould, returnNoneWhenShapesWereAddedAndDeleted)
{
    const rt::core::Point3 origin{};
    const rt::core::Vector3 direction{};
    const rt::core::Ray ray{origin, direction};

    rt::shape::base::HittableList hittableList{};
    hittableList.add(std::make_unique<rt::shape::Sphere>());
    hittableList.add(std::make_unique<rt::shape::Sphere>());
    hittableList.add(std::make_unique<rt::shape::Sphere>());
    hittableList.clear();

    const auto result = hittableList.getClosestHitRecord(ray, 0, 10);

    EXPECT_FALSE(result);
}