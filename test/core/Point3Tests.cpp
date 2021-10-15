#include <gtest/gtest.h>

#include "core/Point3.hpp"
#include "core/Vector3.hpp"

TEST(Point3Should, setDefaultCoordinates)
{
    const rt::core::Point3 point{};

    EXPECT_DOUBLE_EQ(point.x(), 0.0);
    EXPECT_DOUBLE_EQ(point.y(), 0.0);
    EXPECT_DOUBLE_EQ(point.z(), 0.0);
}

TEST(Point3Should, setGivenCoordinates)
{
    const rt::core::Point3 point{1.1, 2.2, 3.0};
    
    EXPECT_DOUBLE_EQ(point.x(), 1.1);
    EXPECT_DOUBLE_EQ(point.y(), 2.2);
    EXPECT_DOUBLE_EQ(point.z(), 3.0);
}

TEST(Point3Should, addVector)
{
    const rt::core::Point3 point{1.1, 2.2, 3.0};
    const rt::core::Vector3 vector{1, 1, 1};
    const rt::core::Point3 result = point + vector;

    EXPECT_DOUBLE_EQ(result.x(), 2.1);
    EXPECT_DOUBLE_EQ(result.y(), 3.2);
    EXPECT_DOUBLE_EQ(result.z(), 4.0);
}

TEST(Point3Should, subtractVector)
{
    const rt::core::Point3 point{5.1, 2.2, 3.0};
    const rt::core::Vector3 vector{1, 1, 1};
    const rt::core::Point3 result = point - vector;

    EXPECT_DOUBLE_EQ(result.x(), 4.1);
    EXPECT_DOUBLE_EQ(result.y(), 1.2);
    EXPECT_DOUBLE_EQ(result.z(), 2.0);
}

TEST(Point3Should, subtractPoint)
{
    const rt::core::Point3 point{4.1, 2.2, 3.0};
    const rt::core::Point3 anotherPoint{1, 1, 1};
    const rt::core::Vector3 result = point - anotherPoint;

    EXPECT_DOUBLE_EQ(result.x(), 3.1);
    EXPECT_DOUBLE_EQ(result.y(), 1.2);
    EXPECT_DOUBLE_EQ(result.z(), 2.0);
}

TEST(Point3Should, bePrintable)
{
    const rt::core::Point3 point{1.0, 2.0, 3.0};

    EXPECT_EQ(point.toString(), "(1.000000, 2.000000, 3.000000)");
}
