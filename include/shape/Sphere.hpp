#ifndef RAYTRACER_SHAPE_SPHERE_HPP
#define RAYTRACER_SHAPE_SPHERE_HPP

#include <memory>

#include "core/Point3.hpp"
#include "core/Ray.hpp"

#include "shape/base/IHittable.hpp"
#include "shape/base/HitRecord.hpp"
#include "shape/material/IMaterial.hpp"

namespace rt::shape
{

class Sphere : public base::IHittable
{
public:
    Sphere();
    Sphere(const std::shared_ptr<material::IMaterial>& material, const core::Point3& center, double radius);

    std::optional<double> gotHittedByRay(const core::Ray& ray, const double tmin,
        const double tmax) const override;
    base::HitRecord calculateHitRecord(const core::Ray& ray, const double t) const override;

private:
    std::shared_ptr<material::IMaterial> material_;
    core::Point3 center_;
    double radius_;
};

} // rt::shape

#endif // RAYTRACER_SHAPE_SPHERE_HPP
