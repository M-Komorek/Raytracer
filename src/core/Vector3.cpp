#include <cmath>

#include "core/Vector3.hpp"

namespace rt::core
{

Vector3::Vector3() : Base3Object()
{
}

Vector3::Vector3(const double x, const double y, const double z)
    : Base3Object(x, y, z)
{
}

Vector3 Vector3::operator+(const Vector3& vector) const
{
    return Vector3(x_+vector.x(), y_+vector.y(), z_+vector.z());
}

Vector3 Vector3::operator-(const Vector3& vector) const
{
    return Vector3(x_-vector.x(), y_-vector.y(), z_-vector.z());
}

Vector3& Vector3::operator+=(const Vector3& vector)
{
    x_ += vector.x();
    y_ += vector.y();
    z_ += vector.z();
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& vector)
{
    x_ -= vector.x();
    y_ -= vector.y();
    z_ -= vector.z();
    return *this;
}

Vector3 Vector3::operator*(const double scale) const
{
    return Vector3(x_*scale, y_*scale, z_*scale);
}

Vector3 Vector3::operator/(const double scale) const
{
    return Vector3(x_/scale, y_/scale, z_/scale);
}

double Vector3::length() const
{
    return std::sqrt(x_*x_ + y_*y_ + z_*z_);
}

double Vector3::scalarProduct(const Vector3& vec) const
{
    return x_*vec.x() + y_*vec.y() + z_*vec.z();
}

Vector3 Vector3::crossProduct(const Vector3& vec) const
{
    const double crossProductX = y_*vec.z() - z_*vec.y();
    const double crossProductY = z_*vec.x() - x_*vec.z();
    const double crossProductZ = x_*vec.y() - y_*vec.x();
    return Vector3(crossProductX, crossProductY, crossProductZ);
}

Vector3 Vector3::normalize()
{
    const double length = this->length();
    return Vector3(x_/length, y_/length, z_/length);
}

bool Vector3::isAlmostZero() const
{
    const auto s = 1e-9;
    return (fabs(x_) < s) && (fabs(y_) < s) && (fabs(z_) < s);
}

std::string Vector3::toString() const
{
    return std::string("[" + std::to_string(x_) + ", "
                           + std::to_string(y_) + ", "
                           + std::to_string(z_) + "]");
}

} // rt::core
