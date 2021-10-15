#include <gtest/gtest.h>

#include "core/Base3Object.hpp"

TEST(Base3ObjectShould, setDefaultCoordinates)
{
    const rt::core::Base3Object base3Object{};

    EXPECT_DOUBLE_EQ(base3Object.x(), 0.0);
    EXPECT_DOUBLE_EQ(base3Object.y(), 0.0);
    EXPECT_DOUBLE_EQ(base3Object.z(), 0.0);
}

TEST(Base3ObjectShould, setGivenCoordinates)
{
    const rt::core::Base3Object base3Object{1.1, 2.2, 3.0};
    
    EXPECT_DOUBLE_EQ(base3Object.x(), 1.1);
    EXPECT_DOUBLE_EQ(base3Object.y(), 2.2);
    EXPECT_DOUBLE_EQ(base3Object.z(), 3.0);
}

TEST(Base3ObjectShould, bePrintable)
{
    const rt::core::Base3Object base3Object{1.0, 2.0, 3.0};

    EXPECT_EQ(base3Object.toString(), "<Base3Object> 1.000000, 2.000000, 3.000000");
}