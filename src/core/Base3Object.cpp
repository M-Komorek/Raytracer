#include "core/Base3Object.hpp"

#include <cmath>
#include <limits>

#include <iostream>

namespace rt::core
{

Base3Object::Base3Object() : x_(0.0), y_(0.0), z_(0.0)
{
}

Base3Object::Base3Object(const double x, const double y, const double z)
    : x_(x), y_(y), z_(z)
{
}

double Base3Object::x() const {return x_;}
double Base3Object::y() const {return y_;}
double Base3Object::z() const {return z_;}

std::string Base3Object::toString() const
{
    return std::string("<Base3Object> "
                        + std::to_string(x_) + ", "
                        + std::to_string(y_) + ", "
                        + std::to_string(z_));
}

} // rt::core
