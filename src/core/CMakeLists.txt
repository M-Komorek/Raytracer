include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/core)

file(GLOB_RECURSE CORE
    "./*.cpp"
)

add_library(core ${CORE})
