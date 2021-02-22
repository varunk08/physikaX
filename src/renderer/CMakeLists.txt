set (RENDERER_SRC 
    renderer.cpp
)

if (ENABLE_VULKAN)
    message("Enabling vulkan renderer")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_HEADER_VERSION=169")
    set (RENDERER_SRC ${RENDERER_SRC}
        vulkan/vkRenderer.cpp)

    if(ANDROID)
        # Android vulkan function pointers are linked dynamically.
        set (RENDERER_SRC ${RENDERER_SRC}
                ${CMAKE_CURRENT_SOURCE_DIR}/../../include/vulkan/vulkan_wrapper.cpp)
        # This is required to allow us to compile the Vulkan C++ header successfully.
        add_definitions(-DVULKAN_HPP_TYPESAFE_CONVERSION)
    endif(ANDROID)

#    find_package(vulkan REQUIRED)
#    if (NOT VULKAN_FOUND)
#        message(SEND_ERROR "Vulkan not found " ${VULKAN_FOUND})
#    else()
#        message(STATUS "Vulkan found at " ${Vulkan_LIBRARY})
#    endif()
endif()

#phi_add_library(physika_renderer STATIC SOURCES ${RENDERER_SRC})
add_library(physika_renderer STATIC ${RENDERER_SRC})

target_include_directories(physika_renderer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include)