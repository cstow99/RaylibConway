cmake_minimum_required(VERSION 3.2)
set(PROJECT_NAME ConwayRaylib)

option(STATIC_BUILD "Statically link Raylib into ${PROJECT_NAME} (No .so/.dll files required)\nThis will also increase the size of the executable.\n\nOn Windows builds you may need to provide the static libraries yourself." OFF)

if(WIN32)
	set(RAYLIB_DIR "${RAYLIB_DIR}" CACHE PATH "Where Raylib is located")
ENDIF(WIN32)

if(${STATIC_BUILD} AND WIN32 AND MSVC)
	set(RAYLIB_STATIC_LIB "${RAYLIB_STATIC_LIB}" CACHE STRING "Raylib static library (Windows builds)")
endif(${STATIC_BUILD} AND WIN32 AND MSVC)

project(${PROJECT_NAME} CXX)
include_directories(${PROJECT_NAME} "src")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(Raylib REQUIRED)

add_subdirectory(RaylibWrapper)
add_subdirectory(Conway)