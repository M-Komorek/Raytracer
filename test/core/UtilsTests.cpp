#include <gtest/gtest.h>

#include "core/Utils.hpp"

TEST(UtilsShould, calculateDegreesToRadians)
{
    double expectedResult = rt::core::degreesToRadians(120);
    EXPECT_NEAR(expectedResult, 2.0944, 0.0001);

    expectedResult = rt::core::degreesToRadians(90);
    EXPECT_NEAR(expectedResult, 1.5708, 0.0001);
}
