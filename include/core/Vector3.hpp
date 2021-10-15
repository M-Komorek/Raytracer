#ifndef RAYTRACER_CORE_VECTOR3_HPP
#define RAYTRACER_CORE_VECTOR3_HPP

#include "core/Base3Object.hpp"
#include "core/Utils.hpp"

namespace rt::core
{

class Vector3 : public Base3Object
{
public:
    Vector3();
    Vector3(const double x, const double y, const double z);

    Vector3 operator+(const Vector3& vector) const;
    Vector3 operator-(const Vector3& vector) const;
    Vector3& operator+=(const Vector3& vector);
    Vector3& operator-=(const Vector3& vector);
    Vector3 operator*(const double scale) const;
    Vector3 operator/(const double scale) const;

    double length() const;
    double scalarProduct(const Vector3& vec) const;
    Vector3 crossProduct(const Vector3& vec) const;
    void normalize();

    std::string toString() const override;


    inline static Vector3 generateRandomVector3(const double min = 0, const double max = 1)
    {
        return Vector3(randomDouble(min, max), randomDouble(min, max), randomDouble(min, max));
    }
    
    inline static Vector3 generateRandomVector3InsideUnitSphere()
    {
        while (true)
        {
            const auto randomVectorInsideunitShpere = generateRandomVector3(-1, 1);
            if (randomVectorInsideunitShpere.length() >= 1)
                continue;
            return randomVectorInsideunitShpere;
        }
    }
};

} // rt::core

#endif // RAYTRACER_CORE_VECTOR3_HPP
