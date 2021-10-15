#include "core/Ray.hpp"

namespace rt::core
{

Ray::Ray(const Point3& origin, const Vector3& direction)
    : origin_{origin}, direction_{direction}
{
}

Point3 Ray::getOrigin() const {return origin_;}
Vector3 Ray::getDirection() const {return direction_;}

void Ray::setOrigin(const Point3& origin)
{
    origin_ = origin;
}

void Ray::setDirection(const Vector3& direction)
{
    direction_ = direction;
}

Point3 Ray::at(const double t) const
{
    return origin_ + direction_*t;
}

std::string Ray::toString() const
{
    return std::string("Origin: " + origin_.toString() +
                       " Direction: " + direction_.toString());
}

} // rt::core
