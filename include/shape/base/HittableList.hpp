#ifndef RAYTRACER_SHAPE_BASE_HITTABLELIST_HPP
#define RAYTRACER_SHAPE_BASE_HITTABLELIST_HPP

#include <memory>
#include <vector>

#include "core/Ray.hpp"

#include "shape/base/IHittable.hpp"
#include "shape/base/HitRecord.hpp"

namespace rt::shape::base
{

class HittableList
{
public:
    HittableList() = default;

    void add(std::unique_ptr<IHittable>&& shape);
    void clear();

    std::optional<HitRecord> getClosestHitRecord(
        const core::Ray& ray, const double tmin, const double tmax) const;

private:
    std::vector<std::unique_ptr<IHittable>> shapes_;
};

} // rt::shape::base

#endif // RAYTRACER_SHAPE_BASE_HITTABLELIST_HPP
