#include "core/Point3.hpp"

namespace rt::core
{

Point3::Point3() : Base3Object()
{
}

Point3::Point3(const double x, const double y, const double z)
    : Base3Object(x, y, z)
{
}

Point3 Point3::operator+(const Vector3& vector) const
{
    return Point3(x_+vector.x(), y_+vector.y(), z_+vector.z());
}

Point3 Point3::operator-(const Vector3& vector) const
{
    return Point3(x_-vector.x(), y_-vector.y(), z_-vector.z());
}

Vector3 Point3::operator-(const Point3& point) const
{
    return Vector3(x_-point.x(), y_-point.y(), z_-point.z());
}


std::string Point3::toString() const
{
    return std::string("(" + std::to_string(x_) + ", "
                           + std::to_string(y_) + ", "
                           + std::to_string(z_) + ")");
}

} // rt::core
