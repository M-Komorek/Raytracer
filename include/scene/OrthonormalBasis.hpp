#ifndef RAYTRACER_SCENE_ORTHONORMAL_BASIS_HPP
#define RAYTRACER_SCENE_ORTHONORMAL_BASIS_HPP

#include "core/Vector3.hpp"

namespace rt::scene
{

struct OrthonormalBasis
{
    const core::Vector3 xAxisDirection;
    const core::Vector3 yAxisDirection;
    const core::Vector3 zAxisDirection;
};

} // rt::scene

#endif // RAYTRACER_SCENE_ORTHONORMAL_BASIS_HPP
