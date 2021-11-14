#include "scene/Camera.hpp"

#include <cmath>
#include <optional>

#include "core/Utils.hpp"
#include "shape/base/HitRecord.hpp"
#include "shape/material/IMaterial.hpp"

namespace rt::scene
{

Camera::Camera(const core::Point3& origin, const core::Point3& lowerLeftCorner,
    const core::Vector3& horizontal, const core::Vector3& vertical)
    : origin_(origin), lowerLeftCorner_(lowerLeftCorner), horizontal_(horizontal), vertical_(vertical)
{
}

Camera Camera::create(const core::Point3& lookFrom, const core::Point3& lookAt,
    double cameraViewingAngle , const double imageRatio)
{
    const auto cameraViewingAngleInRadians = core::degreesToRadians(cameraViewingAngle);
    const auto viewPointHeight = 2.0 * std::tan(cameraViewingAngleInRadians/2);
    const auto viewPointWidth = imageRatio * viewPointHeight;

    // Base (w,u,v) that describe camera orientation
    const auto w = (lookFrom-lookAt).normalize();
    const auto u = core::Vector3{0,1,0}.crossProduct(w).normalize();
    const auto v = w.crossProduct(u);

    const auto horizontal = u * viewPointWidth;
    const auto vertical =  v * viewPointHeight;
    const auto lowerLeftCorner = lookFrom - horizontal/2 - vertical/2 - w;

    return Camera{lookFrom, lowerLeftCorner, horizontal, vertical};
}

core::Ray Camera::getRay(const double horizontalOffset, const double verticalOffset) const
{
    return rt::core::Ray(origin_,
        lowerLeftCorner_ + (horizontal_*horizontalOffset) + (vertical_*verticalOffset) - origin_);
}

core::Color Camera::getRayColor(const rt::core::Ray& ray,
    const rt::shape::base::HittableList& world, const int depth) const
{
    std::optional<shape::base::HitRecord> hitRecord = world.getClosestHitRecord(
        ray, 0.001, std::numeric_limits<double>::infinity());
    
    if (depth <= 0)
    {
        return core::Color{};
    }

    if(hitRecord)
    {
        const auto scatterRay = hitRecord.value().material->procudeScatterRay(ray, hitRecord.value());
        if (scatterRay)
        {
            return hitRecord.value().material->getReflectedLight() * getRayColor(scatterRay.value(), world, depth-1);
        }
        return rt::core::Color(0,0,0);
    }

    const auto normalizeRayDirection = ray.getDirection().normalize();
    const auto t = 0.5*(normalizeRayDirection.y() + 1.0);
    return core::Color(1.0, 1.0, 1.0)*(1.0-t) + core::Color(0.5, 0.7, 1.0)*t;
}

} // rt::scene
