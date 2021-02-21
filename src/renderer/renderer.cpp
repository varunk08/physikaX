#include "renderer.h"
#include "vulkan/vkRenderer.h"
#include <stdexcept>

Renderer *Renderer::CreateRenderer(const RendererType &renderer_type) {
    Renderer* pRenderer = nullptr;
    if (renderer_type == RendererType::VULKAN) {
        pRenderer = new VkRenderer();
    } else {
        throw std::domain_error("Only vulkan renderer supported for now.");
    }

    return pRenderer;
}

Renderer::Renderer() {

}

Renderer::~Renderer() {
    
}

