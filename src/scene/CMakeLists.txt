include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/scene)

file(GLOB_RECURSE CORE
    "./*.cpp"
)

add_library(scene ${CORE})
