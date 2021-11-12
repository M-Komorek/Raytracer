#ifndef RAYTRACER_SHAPE_BASE_HITRECORD_HPP
#define RAYTRACER_SHAPE_BASE_HITRECORD_HPP

#include <memory>

#include "core/Point3.hpp"
#include "core/Ray.hpp"
#include "core/Vector3.hpp"

namespace rt::shape::material
{
    class IMaterial;
}

namespace rt::shape::base
{

struct HitRecord
{
    double t;
    bool frontFace;
    core::Point3 borderPoint;
    core::Vector3 normal;
    std::shared_ptr<material::IMaterial> material;

    inline void setFrontFaceAndNormal(const core::Ray& ray, const core::Vector3& outwardNormal)
    {
        frontFace = ray.getDirection().scalarProduct(outwardNormal) < 0;
        normal = frontFace ? outwardNormal : outwardNormal*(-1);
    }
};

} // rt::shape::base

#endif // RAYTRACER_SHAPE_BASE_HITRECORD_HPP
