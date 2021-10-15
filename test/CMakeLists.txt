set(projectName "RaytracerTests")
cmake_minimum_required(VERSION 3.16.3)
project(projectName)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE TESTS_SRC
  "./*.cpp"
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

add_executable(RaytracerTests main.cpp ${TESTS_SRC} ${SRC})
target_link_libraries(RaytracerTests -pthread gtest_main raytracerEngine)
add_test(NAME RaytracerTests COMMAND RaytracerTests)
