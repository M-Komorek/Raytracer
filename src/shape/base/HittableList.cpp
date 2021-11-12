#include "shape/base/HittableList.hpp"

namespace rt::shape::base
{

void HittableList::add(std::unique_ptr<IHittable>&& shape)
{
    shapes_.push_back(std::move(shape));
}

void HittableList::clear()
{
    shapes_.clear();
}

std::optional<HitRecord> HittableList::getClosestHitRecord(
    const core::Ray& ray, const double tmin, const double tmax) const
{
    double closestSoFar = tmax;
    std::optional<HitRecord> closestHitRecord{};
    for (const auto& shape : shapes_)
    {
        const std::optional<double> time = shape->gotHittedByRay(ray, tmin, closestSoFar);
        if (time)
        {
            closestHitRecord.emplace(shape->calculateHitRecord(ray, time.value()));
            closestSoFar = time.value();
        }
    }

    if (closestHitRecord)
        return closestHitRecord;
    else
        return std::nullopt;
}

} // rt::shape::base
