#include <gtest/gtest.h>

#include "TestUtils.hpp"

#include "core/Vector3.hpp"

TEST(Vector3Should, setDefaultCoordinates)
{
    const rt::core::Vector3 vector{};

    EXPECT_DOUBLE_EQ(vector.x(), 0.0);
    EXPECT_DOUBLE_EQ(vector.y(), 0.0);
    EXPECT_DOUBLE_EQ(vector.z(), 0.0);
}

TEST(Vector3Should, setGivenCoordinates)
{
    const rt::core::Vector3 vector{1.1, 2.2, 3.0};

    EXPECT_DOUBLE_EQ(vector.x(), 1.1);
    EXPECT_DOUBLE_EQ(vector.y(), 2.2);
    EXPECT_DOUBLE_EQ(vector.z(), 3.0);
}

TEST(Vector3Should, addVector)
{
    const rt::core::Vector3 vector{1.1, 2.2, 3.0};
    const rt::core::Vector3 anotherVector{1.1, 2.2, 3.0};

    const rt::core::Vector3 result = vector + anotherVector;
    const rt::core::Vector3 expectedResult{2.2, 4.4, 6.0};

    testUtils::isEqual<rt::core::Vector3>(result, expectedResult);
}

TEST(Vector3Should, subtractVector)
{
    const rt::core::Vector3 vector{1.1, 2.2, 3.0};
    const rt::core::Vector3 anotherVector{1.1, 2.2, 3.0};

    const rt::core::Vector3 result = vector - anotherVector;
    const rt::core::Vector3 expectedResult{};

    testUtils::isEqual<rt::core::Vector3>(result, expectedResult);
}

TEST(Vector3Should, addFewVector)
{
    rt::core::Vector3 vector{5.1, 5.2, 5.0};
    const rt::core::Vector3 anotherVector{1, 1, 1};

    for (int i=0; i<3; ++i)
        vector += anotherVector;
    
    const rt::core::Vector3 expectedResult{8.1, 8.2, 8.0};

    testUtils::isEqual<rt::core::Vector3>(vector, expectedResult);
}

TEST(Vector3Should, subtractFewVector)
{
    rt::core::Vector3 vector{5.1, 5.2, 5.0};
    const rt::core::Vector3 anotherVector{1, 1, 1};

    for (int i=0; i<3; ++i)
        vector -= anotherVector;
    
    const rt::core::Vector3 expectedResult{2.1, 2.2, 2.0};

    testUtils::isEqual<rt::core::Vector3>(vector, expectedResult);
}

TEST(Vector3Should, multiplyByScalar)
{
    rt::core::Vector3 vector{1.1, 2.2, 3.0};
    vector = vector * 2;

    const rt::core::Vector3 expectedResult{2.2, 4.4, 6.0};

    testUtils::isEqual<rt::core::Vector3>(vector, expectedResult);
}

TEST(Vector3Should, divisibleByScalar )
{
    rt::core::Vector3 vector{1.1, 2.2, 3.0};
    vector = vector / 2;

    const rt::core::Vector3 expectedResult{0.55, 1.1, 1.5};

    testUtils::isEqual<rt::core::Vector3>(vector, expectedResult);
}

TEST(Vector3Should, calculateLength)
{
    const rt::core::Vector3 vec{3.0, 4.0, 4.0};
    const auto result = vec.length();

    const double expectedResult = 6.4031;

    EXPECT_NEAR(expectedResult, result, 0.0001);
}

TEST(Vector3Should, calculateScalarProduct)
{
    const rt::core::Vector3 vec1{2.0, 3.0, 4.0};
    const rt::core::Vector3 vec2{3.0, 4.0, 5.0};

    const auto result = vec1.scalarProduct(vec2);
    const double expectedResult = 38;
    
    EXPECT_DOUBLE_EQ(expectedResult, result);
}

TEST(Vector3Should, calculateCrossProduct)
{
    const rt::core::Vector3 vec1{2.0, 3.0, 4.0};
    const rt::core::Vector3 vec2{3.0, 4.0, 5.0};
    const rt::core::Vector3 result = vec1.crossProduct(vec2);

    const rt::core::Vector3 expectedResult{-1.0, 2.0, -1.0};

    testUtils::isEqual<rt::core::Vector3>(result, expectedResult);
}

TEST(Vector3Should, makeNormalize)
{
    rt::core::Vector3 vector{3.0, 4.0, 0.0};
    const rt::core::Vector3 normalized = vector.normalize();

    const rt::core::Vector3 expectedResult{0.6, 0.8, 0.0};

    testUtils::isEqual<rt::core::Vector3>(normalized, expectedResult);
}

TEST(Vector3Should, bePrintable)
{
    const rt::core::Vector3 vec{1.0, 2.0, 3.0};
    const auto result = vec.toString();

    const std::string expectedResult = "[1.000000, 2.000000, 3.000000]";

    EXPECT_EQ(expectedResult, result);
}
