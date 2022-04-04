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

Vector3 Vector3::generateRandomVector3(const double min, const double max)
{
    return Vector3(randomDouble(min, max), randomDouble(min, max), randomDouble(min, max));
}

Vector3 Vector3::generateRandomVector3InsideUnitCircle()
{
    while (true)
    {
        const auto randomVectorInsideUnitCircle = Vector3{randomDouble(-1, 1), randomDouble(-1, 1), 0};
        if (randomVectorInsideUnitCircle.length() >= 1)
        {
            continue;
        }
        return randomVectorInsideUnitCircle;
    }
}

Vector3 Vector3::generateRandomVector3InsideUnitSphere()
{
    while (true)
    {
        const auto randomVectorInsideunitShpere = generateRandomVector3(-1, 1);
        if (randomVectorInsideunitShpere.length() >= 1)
        {
            continue;
        }
        return randomVectorInsideunitShpere;
    }
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
    return Vector3(y_*vec.z() - z_*vec.y(),
                   z_*vec.x() - x_*vec.z(),
                   x_*vec.y() - y_*vec.x());
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
