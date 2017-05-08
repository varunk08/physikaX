cmake_minimum_required(VERSION 3.4)

project(PhysikaX)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/_build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake-modules)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 3rd Party
find_package(gtest)
find_package(glfw)

# src dir
add_subdirectory(./src/simple-project)

