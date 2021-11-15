#include "scene/Camera.hpp"

#include <cmath>
#include <optional>

#include "core/Utils.hpp"
#include "shape/base/HitRecord.hpp"
#include "shape/material/IMaterial.hpp"

namespace rt::scene
{

Camera::Camera(const core::Point3& pointOfView, const OrthonormalBasis& orthonormalBasis,
    const View& view, const double convergingLensRadius)
    : pointOfView_(pointOfView)
    , orthonormalBasis_(orthonormalBasis)
    , view_(view)
    , convergingLensRadius_(convergingLensRadius)
{
}

Camera Camera::create(const core::Point3& lookFromPoint, const core::Point3& lookAtPoint,
    double cameraViewingAngle , const double imageRatio, const double convergingLensRadius)
{
    const auto cameraViewingAngleInRadians = core::degreesToRadians(cameraViewingAngle);
    const auto viewPointHeight = 2.0 * std::tan(cameraViewingAngleInRadians/2);
    const auto viewPointWidth = imageRatio * viewPointHeight;

    const auto z = (lookFromPoint-lookAtPoint).normalize();
    const auto x = core::Vector3{0,1,0}.crossProduct(z).normalize();
    const auto y = z.crossProduct(x);
    const OrthonormalBasis orthonormalBasis{x, y, z};

    const auto cameraToSceneDistance = (lookFromPoint - lookAtPoint).length();
    const auto horizontalSpanOfTheScene = x * viewPointWidth * cameraToSceneDistance;
    const auto verticalSpanOfTheScene = y * viewPointHeight * cameraToSceneDistance;
    const auto lowerLeftCornerOfTheScene = lookFromPoint - horizontalSpanOfTheScene/2 -
        verticalSpanOfTheScene/2 - z*cameraToSceneDistance;
    const View view{lowerLeftCornerOfTheScene, horizontalSpanOfTheScene, verticalSpanOfTheScene};

    return Camera{lookFromPoint, orthonormalBasis, view, convergingLensRadius};
}

core::Ray Camera::getRay(const double horizontalOffset, const double verticalOffset) const
{
    const auto randomDirection = core::Vector3::generateRandomVector3InsideUnitCircle() * convergingLensRadius_;
    const auto offSet = orthonormalBasis_.xAxisDirection * randomDirection.x() +
        orthonormalBasis_.yAxisDirection * randomDirection.y();

    return rt::core::Ray(pointOfView_ + offSet,
        view_.lowerLeftCornerOfTheScene + (view_.horizontalSpanOfTheScene*horizontalOffset) +
            (view_.verticalSpanOfTheScene*verticalOffset) - pointOfView_ - offSet);
}

core::Color Camera::getRayColor(const rt::core::Ray& ray,
    const rt::shape::base::HittableList& world, const int depth) const
{
    if (depth <= 0)
    {
        return core::Color{};
    }

    std::optional<shape::base::HitRecord> hitRecord = world.getClosestHitRecord(
        ray, 0.001, std::numeric_limits<double>::infinity());
    

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
