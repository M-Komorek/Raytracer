#ifndef RAYTRACER_SHAPE_MATERIAL_MATTE_HPP
#define RAYTRACER_SHAPE_MATERIAL_MATTE_HPP

#include "core/Color.hpp"
#include "core/Ray.hpp"
#include "shape/material/IMaterial.hpp"

namespace rt::shape::material
{

class Matte : public IMaterial
{
public:
    Matte(const core::Color& reflectedLight);
    
    core::Color getReflectedLight() const override;
    std::optional<core::Ray> procudeScatterRay(
        const core::Ray& fallingRay, const base::HitRecord& hitRecord) const override;

private:
    const core::Color reflectedLight_;
    
};

} // rt::shape::material

#endif // RAYTRACER_SHAPE_MATERIAL_MATTE_HPP
