#ifndef RAYTRACER_CORE_BASE3OBJECT_HPP
#define RAYTRACER_CORE_BASE3OBJECT_HPP

#include <string>

namespace rt::core
{

class Base3Object
{
public:
    Base3Object();
    Base3Object(const double x, const double y, const double z);
    virtual ~Base3Object() = default;

    double x() const;
    double y() const;
    double z() const;

    virtual std::string toString() const;

protected:
    double x_;
    double y_;
    double z_;
};

} // rt::core

#endif // RAYTRACER_CORE_BASE3OBJECT_HPP
