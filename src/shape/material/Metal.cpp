#include "shape/material/Metal.hpp"

#include "core/Vector3.hpp"

namespace rt::shape::material
{

Metal::Metal(const core::Color& reflectedLight, const double fuzzy) 
    : reflectedLight_{reflectedLight}, fuzzy_{fuzzy}
{
}

core::Color Metal::getReflectedLight() const
{
    return reflectedLight_;
}

std::optional<core::Ray> Metal::procudeScatterRay(
    const core::Ray& fallingRay, const base::HitRecord& hitRecord) const
{
    const auto fallingRayDirectionNormalized = fallingRay.getDirection().normalize();
    const auto reflectedDirection = fallingRayDirectionNormalized - 
        hitRecord.normal*2*(fallingRayDirectionNormalized.scalarProduct(hitRecord.normal));

    const core::Ray scatteredRay{hitRecord.borderPoint,
        reflectedDirection + core::Vector3::generateRandomVector3InsideUnitSphere()*fuzzy_};
    
    if (scatteredRay.getDirection().scalarProduct(hitRecord.normal) > 0)
        return std::optional<core::Ray>{scatteredRay};
    else
        return std::nullopt;
}

} // rt::shape::material