#include "scene/Camera.hpp"

namespace rt::scene
{

Camera::Camera()
{
    const auto imageRatio = 16.0 / 9.0;
    const auto scenePortHeight = 2.0;
    const auto scenePortWidth = imageRatio * scenePortHeight;
    
    origin_ = core::Point3();
    horizontal_ = core::Vector3(scenePortWidth, 0, 0);
    vertical_ = core::Vector3(0, scenePortHeight, 0);
    lowerLeftCorner_ = origin_ - horizontal_/2 - vertical_/2 - rt::core::Vector3(0, 0, 1);
}

core::Ray Camera::getRay(const double u, const double v) const
{
    return rt::core::Ray(origin_, lowerLeftCorner_ + horizontal_*u + vertical_*v - origin_);
}

} // rt::scene
