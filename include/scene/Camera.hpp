#ifndef RAYTRACER_SCENE_CAMERA_HPP
#define RAYTRACER_SCENE_CAMERA_HPP

#include "core/Point3.hpp"
#include "core/Ray.hpp"
#include "core/Vector3.hpp"

namespace rt::scene
{

class Camera
{
public:
    Camera();
    core::Ray getRay(const double u, const double v) const;

private:
    core::Point3 origin_;
    core::Point3 lowerLeftCorner_;
    core::Vector3 horizontal_;
    core::Vector3 vertical_;
};

} // rt::scene

#endif // RAYTRACER_SCENE_CAMERA_HPP
