#include <cmath>
#include "shape/Sphere.hpp"

namespace rt::shape
{

Sphere::Sphere() : center_{core::Point3(0.0, 0.0, 0.0)}, radius_{0}
{
}

Sphere::Sphere(const std::shared_ptr<material::IMaterial>& material,
    const core::Point3& center, double radius)
    : material_{material}, center_{center}, radius_{radius}
{
}

std::optional<double> Sphere::gotHittedByRay(const core::Ray& ray, const double tmin,
    const double tmax) const
{
    // Based on the sphere equation
    const core::Vector3 originMinusCenter = ray.getOrigin()-center_;
    const auto a = ray.getDirection().scalarProduct(ray.getDirection());
    const auto halfB = originMinusCenter.scalarProduct(ray.getDirection());
    const auto c = originMinusCenter.scalarProduct(originMinusCenter) - radius_*radius_;

    const auto delta = halfB*halfB - a*c;
    if (delta < 0) {return {};};

    const auto deltaSqrt = std::sqrt(delta);
    auto root = (-halfB-deltaSqrt) / a;
    if (root < tmin || tmax < root)
    {
        root = (-halfB+deltaSqrt) / a;
        if (root < tmin || tmax < root)
        {
            return {};
        }
    }

    return std::make_optional<double>(root);
}

base::HitRecord Sphere::calculateHitRecord(const core::Ray& ray, const double t) const
{
    base::HitRecord hitRecord;
    hitRecord.t = t;
    hitRecord.borderPoint = ray.at(t);
    core::Vector3 outwardNormal = (hitRecord.borderPoint - center_) / radius_;
    hitRecord.setFrontFaceAndNormal(ray, outwardNormal);
    hitRecord.material = material_;
    return hitRecord;
}

} // rt::shape
