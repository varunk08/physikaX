#include "vkRenderer.h"
#include <stdexcept>

#if __ANDROID__
#include <vulkan/vulkan_wrapper.hpp>
#undef VK_NO_PROTOTYPES
#endif

#include <vulkan/vulkan.hpp>

void VkRenderer::Init() {
    vk::ApplicationInfo applicationInfo("Phyika",
                                        1,
                                        "PhysikaX",
                                        1,
                                        VK_API_VERSION_1_1);

    vk::InstanceCreateInfo instanceCreateInfo( {}, &applicationInfo );

    vk::UniqueInstance instance = vk::createInstanceUnique( instanceCreateInfo );
}

VkRenderer::VkRenderer() {
    // Load vulkan library.
    if (!InitVulkan()) {
        throw std::runtime_error("Vulkan not found.");
    }
}
