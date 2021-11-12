#ifndef RAYTRACER_SHAPE_MATERIAL_IMATERIAL_HPP
#define RAYTRACER_SHAPE_MATERIAL_IMATERIAL_HPP

#include <memory>
#include <optional>

#include "core/Color.hpp"
#include "core/Ray.hpp"
#include "shape/base/HitRecord.hpp"

namespace rt::shape::base
{
    class HitRecord;
}

namespace rt::shape::material
{

class IMaterial
{
public:
    virtual ~IMaterial() = default;
    virtual std::optional<core::Ray> procudeScatterRay(
        const core::Ray& fallingRay, const base::HitRecord& hitRecord) const = 0;
    virtual core::Color getReflectedLight() const = 0;
    
};

} // rt::shape::material

#endif // RAYTRACER_SHAPE_MATERIAL_IMATERIAL_HPP
