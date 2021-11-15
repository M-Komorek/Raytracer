#ifndef RAYTRACER_SCENE_VIEW_HPP
#define RAYTRACER_SCENE_VIEW_HPP

#include "core/Point3.hpp"
#include "core/Vector3.hpp"

namespace rt::scene
{

struct View
{
    const core::Point3 lowerLeftCornerOfTheScene;
    const core::Vector3 horizontalSpanOfTheScene;
    const core::Vector3 verticalSpanOfTheScene;
};

} // rt::scene

#endif // RAYTRACER_SCENE_VIEW_HPP
