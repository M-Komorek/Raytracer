include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/shape/base)

file(GLOB_RECURSE BASE
    "./*.cpp"
)

add_library(base ${BASE})
