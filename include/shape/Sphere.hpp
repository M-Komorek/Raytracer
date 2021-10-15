#ifndef RAYTRACER_SHAPE_SPHERE_HPP
#define RAYTRACER_SHAPE_SPHERE_HPP

#include "shape/base/IHittable.hpp"
#include "core/Point3.hpp"

namespace rt::shape
{

class Sphere : public base::IHittable
{
public:
    Sphere();
    Sphere(core::Point3 center, double radius);

    std::optional<double> gotHittedByRay(const core::Ray& ray, const double& tmin,
        const double& tmax) const override;
    base::HitRecord calculateHitRecord(const core::Ray& ray, const double& t) const override;

private:
    core::Point3 center_;
    double radius_;
};

} // rt::shape

#endif // RAYTRACER_SHAPE_SPHERE_HPP
