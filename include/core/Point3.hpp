#ifndef RAYTRACER_CORE_POINT3_HPP
#define RAYTRACER_CORE_POINT3_HPP

#include "core/Base3Object.hpp"
#include "core/Vector3.hpp"

namespace rt::core
{

class Point3 : public Base3Object
{
public:
    Point3();
    Point3(const double x, const double y, const double z);

    Point3 operator+(const Vector3& vector) const;
    Point3 operator-(const Vector3& vector) const;
    Vector3 operator-(const Point3& point) const;

    std::string toString() const override;
};

} // rt::core

#endif // RAYTRACER_CORE_POINT3_HPP
