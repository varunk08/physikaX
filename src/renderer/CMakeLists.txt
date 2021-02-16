set (RENDERER_SRC 
    renderer.cpp
    #vulkan/vkRenderer.cpp
)

if (ENABLE_VULKAN)
    message("Enabling vulkan renderer")
    set (RENDERER_SRC ${RENDERER_SRC}
        vulkan/vkRenderer.cpp)

    find_package(vulkan REQUIRED)
    if (NOT VULKAN_FOUND)
        message(SEND_ERROR "Vulkan not found")
    else()
        message(STATUS "Vulkan found at " ${Vulkan_LIBRARY})
    endif()

endif()

#phi_add_library(physika_renderer STATIC SOURCES ${RENDERER_SRC})
add_library(physika_renderer STATIC ${RENDERER_SRC})

target_include_directories(physika_renderer PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include)