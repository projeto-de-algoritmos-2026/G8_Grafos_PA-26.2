cmake_minimum_required(VERSION 3.11)
project(CavaloRaylib)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)
FetchContent_MakeAvailable(raylib)

add_executable(CavaloRaylib main.cpp)
target_link_libraries(CavaloRaylib PRIVATE raylib)

if (UNIX AND NOT APPLE)
    target_link_libraries(CavaloRaylib PRIVATE m pthread dl rt X11)
endif()
