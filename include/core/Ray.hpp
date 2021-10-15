#ifndef RAYTRACER_CORE_RAY_HPP
#define RAYTRACER_CORE_RAY_HPP

#include "core/Point3.hpp"
#include "core/Vector3.hpp"

namespace rt::core
{

class Ray
{
public:
    Ray(const Point3& origin, const Vector3& direction);

    Point3 getOrigin() const;
    Vector3 getDirection() const;
    void setOrigin(const Point3& origin);
    void setDirection(const Vector3& direction);

    Point3 at(const double t) const;

    std::string toString() const;

private:
    Point3 origin_;
    Vector3 direction_;
};

} // rt::core

#endif // RAYTRACER_CORE_RAY_HPP
