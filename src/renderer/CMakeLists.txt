set (RENDERER_SRC 
    renderer.cpp
    #vulkan/vkRenderer.cpp
)

#phi_add_library(physika_renderer STATIC SOURCES ${RENDERER_SRC})
add_library(physika_renderer STATIC ${RENDERER_SRC})

target_include_directories(physika_renderer PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include)