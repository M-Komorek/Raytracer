#include <gtest/gtest.h>

#include "TestUtils.hpp"

#include "core/Color.hpp"


TEST(ColorShould, setDefaultRGB)
{
    const rt::core::Color color{};

    EXPECT_DOUBLE_EQ(color.red(), 0.0);
    EXPECT_DOUBLE_EQ(color.green(), 0.0);
    EXPECT_DOUBLE_EQ(color.blue(), 0.0);
}

TEST(ColorShould, setGivenRGBValues)
{
    const rt::core::Color color{1.1, 2.2, 3.0};

    EXPECT_DOUBLE_EQ(color.red(), 1.1);
    EXPECT_DOUBLE_EQ(color.green(), 2.2);
    EXPECT_DOUBLE_EQ(color.blue(), 3.0);
}

TEST(ColorShould, addColor)
{
    const rt::core::Color color{1.1, 2.2, 3.0};
    const rt::core::Color anotherColor{1.1, 2.2, 3.0};

    const rt::core::Color result = color + anotherColor;
    const rt::core::Color expectedResult{2.2, 4.4, 6.0};

    testUtils::isEqual<rt::core::Color>(result, expectedResult);
}

TEST(ColorShould, addFewColors)
{
    rt::core::Color color{5.1, 5.2, 5.0};
    const rt::core::Color anotherColor{1, 1, 1};

    for (int i=0; i<3; ++i)
        color += anotherColor;
    
    const rt::core::Color expectedResult{8.1, 8.2, 8.0};

    testUtils::isEqual<rt::core::Color>(color, expectedResult);
}

TEST(ColorShould, multiplyByScalar)
{
    rt::core::Color color{1.1, 2.2, 3.0};
    color = color * 2;

    const rt::core::Color expectedResult{2.2, 4.4, 6.0};

    testUtils::isEqual<rt::core::Color>(color, expectedResult);
}

TEST(ColorShould, serializeToStream)
{
    rt::core::Color color{1.1, 2.2, 3.0};
    std::ostringstream stream;

    color.serializeToStream(10, stream);

    EXPECT_EQ(stream.str(), "84 120 140\n");
}

TEST(ColorShould, bePrintable)
{
    const rt::core::Color color{1.0, 2.0, 3.0};
    const auto result = color.toString();

    const auto expectedResult = "{1.000000, 2.000000, 3.000000}";

    EXPECT_EQ(expectedResult, result);
}
