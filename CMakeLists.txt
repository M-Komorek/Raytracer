set(projectName "Raytracer")
cmake_minimum_required(VERSION 3.16.3)
project(${projectName})

option(test "Build all tests." ON)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    include)

add_subdirectory(src)

add_executable(${projectName} main.cpp)

target_link_libraries(
    ${projectName}
    raytracerEngine)

if (test)
    enable_testing()
    add_subdirectory(test)
endif()
