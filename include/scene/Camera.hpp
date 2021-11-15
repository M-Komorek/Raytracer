#ifndef RAYTRACER_SCENE_CAMERA_HPP
#define RAYTRACER_SCENE_CAMERA_HPP

#include "core/Color.hpp"
#include "core/Point3.hpp"
#include "core/Ray.hpp"
#include "core/Vector3.hpp"

#include "scene/OrthonormalBasis.hpp"
#include "scene/View.hpp"

#include "shape/base/HittableList.hpp"

namespace rt::scene
{

class Camera
{
public:
    Camera(const core::Point3& pointOfView, const OrthonormalBasis& orthonormalBasis,
        const View& view, const double convergingLensRadius = 1);
        
    static Camera create(const core::Point3& lookFromPoint, const core::Point3& lookAtPoint,
        double viewingAngle, const double imageRatio, const double convergingLensRadius);

    core::Ray getRay(const double horizontalOffset, const double verticalOffset) const;
    core::Color getRayColor(const rt::core::Ray& ray,
        const rt::shape::base::HittableList& world, const int depth) const;

private:
    const core::Point3 pointOfView_;
    const OrthonormalBasis orthonormalBasis_;
    const View view_;
    const double convergingLensRadius_;
};

} // rt::scene

#endif // RAYTRACER_SCENE_CAMERA_HPP
