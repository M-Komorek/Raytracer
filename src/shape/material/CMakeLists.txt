include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/shape/material)

file(GLOB_RECURSE MATERIAL
    "./*.cpp"
)

add_library(material ${MATERIAL})
