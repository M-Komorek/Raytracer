#ifndef RAYTRACER_SHAPE_BASE_HITTABLE_HPP
#define RAYTRACER_SHAPE_BASE_HITTABLE_HPP

#include <optional>

#include "shape/base/HitRecord.hpp"

namespace rt::shape::base
{

class IHittable
{
public:
    virtual ~IHittable() = default;
    virtual std::optional<double> gotHittedByRay(const core::Ray& ray, const double& tmin,
        const double& tmax) const = 0;
    virtual base::HitRecord calculateHitRecord(const core::Ray& ray, const double& t) const = 0;
};

} // rt::shape::base

#endif // RAYTRACER_SHAPE_BASE_HITTABLE_HPP
