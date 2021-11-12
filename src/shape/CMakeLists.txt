add_subdirectory(base)
add_subdirectory(material)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/shape)
file(GLOB_RECURSE SHAPE
    "./*.cpp"
)

add_library(shape ${SHAPE})
