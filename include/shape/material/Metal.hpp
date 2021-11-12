#ifndef RAYTRACER_SHAPE_MATERIAL_METAL_HPP
#define RAYTRACER_SHAPE_MATERIAL_METAL_HPP

#include "core/Color.hpp"
#include "shape/material/IMaterial.hpp"

namespace rt::shape::material
{

class Metal : public IMaterial
{
public:
    Metal(const core::Color& reflectedLight, const double fuzzy);
    
    core::Color getReflectedLight() const override;
    std::optional<core::Ray> procudeScatterRay(
        const core::Ray& fallingRay, const base::HitRecord& hitRecord) const override;

private:
    const core::Color reflectedLight_;
    const double fuzzy_;
    
};

} // rt::shape::material

#endif // RAYTRACER_SHAPE_MATERIAL_METAL_HPP
