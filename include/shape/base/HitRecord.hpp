#ifndef RAYTRACER_SHAPE_BASE_HITRECORD_HPP
#define RAYTRACER_SHAPE_BASE_HITRECORD_HPP

#include "core/Ray.hpp"

namespace rt::shape::base
{

struct HitRecord
{
    double t;
    core::Point3 borderPoint;
    core::Vector3 normal;
    bool frontFace;

    inline void setFrontFaceAndNormal(const core::Ray& ray, const core::Vector3& outwardNormal)
    {
        frontFace = ray.getDirection().scalarProduct(outwardNormal) < 0;
        normal = frontFace ? outwardNormal : outwardNormal*(-1);
    }
};

} // rt::shape::base

#endif // RAYTRACER_SHAPE_BASE_HITRECORD_HPP
