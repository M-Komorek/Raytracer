#include <cmath>
#include <random>

namespace rt::core
{

double degreesToRadians(const double degrees) 
{
    return degrees * M_PI / 180.0;
}

double randomDouble(const double min, const double max) 
{
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

} // rt::core