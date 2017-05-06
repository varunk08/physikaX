cmake_minimum_required(VERSION 3.4)

project(PhysikaX)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/_build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(
  gtest_force_shared_crt
  "Use shared (DLL) run-time lib even when Google Test is built as static lib."
  ON)
# 3rd Party
add_subdirectory(./3rdParty/gtest)
add_subdirectory(./3rdParty/glfw-3.2.1)

# src dir
add_subdirectory(./src/simple-project)

