include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/scene)

file(GLOB_RECURSE SCENE
    "./*.cpp"
)

add_library(scene ${SCENE})
