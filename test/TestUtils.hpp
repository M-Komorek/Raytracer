#ifndef RAYTRACERTESTS_TESTUTILS_HPP
#define RAYTRACERTESTS_TESTUTILS_HPP

namespace testUtils
{

template <class threeCoordinatesObject>
void isEqual(const threeCoordinatesObject& firstObject, const threeCoordinatesObject& secondObject) 
{
    EXPECT_DOUBLE_EQ(firstObject.x(), secondObject.x());
    EXPECT_DOUBLE_EQ(firstObject.y(), secondObject.y());
    EXPECT_DOUBLE_EQ(firstObject.z(), secondObject.z());
}

}

#endif // RAYTRACERTESTS_TESTUTILS_HPP