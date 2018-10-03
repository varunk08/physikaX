cmake_minimum_required(VERSION 3.5)

project(PhysikaX)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/_build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake-modules)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Warning Settings
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
endif()

# 3rd Party
find_package(gtest)
#find_package(glfw)

# src dir
#add_subdirectory(./src/simple-project)
#add_subdirectory(./src/app-framework)

function(phi_add_executable PHI_TARGET)
    cmake_parse_arguments(
        PHI
        "WIN32"
        ""
        "SOURCES"
        ${ARGN}
    )

    message("=================${PHI_TARGET}=================")
    message("=================${PHI_SOURCES}=================")
    message("=================${PHI_UNPARSED_ARGUMENTS}=================")
endfunction()

SET(SOURCES main.cpp)
SET(CO main.cpp
        main2.cpp
        main4.cpp)
phi_add_executable(WoW SOURCES ${SOURCES})