#include "vkRenderer.h"
#include <stdexcept>
#include <optional>

#if __ANDROID__
#include <vulkan/vulkan_wrapper.hpp>
#undef VK_NO_PROTOTYPES
#endif
//#define VULKAN_HPP_NO_SMART_HANDLE
#define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC 0
#include <vulkan/vulkan.hpp>

VULKAN_HPP_DEFAULT_DISPATCH_LOADER_DYNAMIC_STORAGE
void VkRenderer::init() {
    vk::ApplicationInfo applicationInfo("Phyika",
                                        1,
                                        "PhysikaX",
                                        1,
                                        VK_API_VERSION_1_1);

    // initialize the vk::InstanceCreateInfo
    vk::InstanceCreateInfo instanceCreateInfo( {}, &applicationInfo );

    // create an Instance
    vk::Instance instance = vk::createInstance( instanceCreateInfo );


    vk::PhysicalDevice physicalDevice = instance.enumeratePhysicalDevices().front();
    std::vector<vk::QueueFamilyProperties> queueFamilyProperties = physicalDevice.getQueueFamilyProperties();
    auto propertyIterator = std::find_if(
            queueFamilyProperties.begin(), queueFamilyProperties.end(), []( vk::QueueFamilyProperties const & qfp ) {
                return qfp.queueFlags & vk::QueueFlagBits::eGraphics;
            } );
    size_t graphicsQueueFamilyIndex = std::distance( queueFamilyProperties.begin(), propertyIterator );
    assert( graphicsQueueFamilyIndex < queueFamilyProperties.size() );

    float queuePriority = 0.0f;
    vk::DeviceQueueCreateInfo deviceQueueCreateInfo(vk::DeviceQueueCreateFlags(),
                                                    static_cast<uint32_t>( graphicsQueueFamilyIndex ),
                                                    1,
                                                    &queuePriority );
    vk::Device device = physicalDevice.createDevice( vk::DeviceCreateInfo( vk::DeviceCreateFlags(),
                                                                                    deviceQueueCreateInfo ) );


    device.destroy(nullptr);
    instance.destroy(nullptr);
}



VkRenderer::VkRenderer() {
    // Load vulkan library.
    if (!InitVulkan()) {
        throw std::runtime_error("Vulkan not found.");
    }
}

void VkRenderer::init_geometry() {

}

void VkRenderer::init_scene() {

}

void VkRenderer::init_camera() {

}

void VkRenderer::draw_frame() {

}
