#ifndef RAYTRACER_SHAPE_BASE_UTILS_HPP
#define RAYTRACER_SHAPE_BASE_UTILS_HPP

#include <cmath>

namespace rt::core
{

inline double degreesToRadians(const double degrees)
{
    return degrees * M_PI / 180.0;
}

inline double randomDouble(const double min = 0, const double max = 1)
{
    return min + static_cast<double>(rand()) / ( static_cast<double>(RAND_MAX/(max-min)));
}

} // rt::core

#endif // RAYTRACER_SHAPE_BASE_UTILS_HPP