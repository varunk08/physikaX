#include <iostream>
#include "../renderer.h"
#include <vulkan/vulkan.hpp>

class VkRenderer : public Renderer {
public:
    VkRenderer();
    void Init() override ;

private:  
};