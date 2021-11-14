#ifndef RAYTRACER_SCENE_CAMERA_HPP
#define RAYTRACER_SCENE_CAMERA_HPP

#include "core/Color.hpp"
#include "core/Point3.hpp"
#include "core/Ray.hpp"
#include "core/Vector3.hpp"

#include "shape/base/HittableList.hpp"

namespace rt::scene
{

class Camera
{
public:
    Camera(const core::Point3& origin, const core::Point3& lowerLeftCorner,
        const core::Vector3& horizontal, const core::Vector3& vertical);
        
    static Camera create(const core::Point3& lookFrom, const core::Point3& lookAt,
        double viewingAngle, const double imageRatio);

    core::Ray getRay(const double horizontalOffset, const double verticalOffset) const;
    core::Color getRayColor(const rt::core::Ray& ray,
        const rt::shape::base::HittableList& world, const int depth) const;

private:
    const core::Point3 origin_;
    const core::Point3 lowerLeftCorner_;
    const core::Vector3 horizontal_;
    const core::Vector3 vertical_;
};

} // rt::scene

#endif // RAYTRACER_SCENE_CAMERA_HPP
