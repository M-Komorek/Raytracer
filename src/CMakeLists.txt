add_subdirectory(core)
add_subdirectory(scene)
add_subdirectory(shape)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE SRC
    "./*.cpp"
)

add_library(raytracerEngine ${SRC})
