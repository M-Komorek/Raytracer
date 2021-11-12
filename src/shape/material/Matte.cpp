#include "shape/material/Matte.hpp"

#include "core/Vector3.hpp"

namespace rt::shape::material
{

Matte::Matte(const core::Color& reflectedLight) : reflectedLight_{reflectedLight}
{
}

core::Color Matte::getReflectedLight() const
{
    return reflectedLight_;
}

std::optional<core::Ray> Matte::procudeScatterRay(
    const core::Ray& fallingRay, const base::HitRecord& hitRecord) const
{
    auto scatterDirection = hitRecord.normal + core::Vector3::generateRandomVector3();
    
    if(scatterDirection.isAlmostZero())
        scatterDirection = hitRecord.normal;
    
    const core::Ray scatteredRay{hitRecord.borderPoint, scatterDirection};
    return std::optional<core::Ray>{scatteredRay};
}

} // rt::shape::material