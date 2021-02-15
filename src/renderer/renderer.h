#include <iostream>

enum RendererType:uint32_t {
    VULKAN = 0,
    DX12,
    OPENGL
};

class Renderer {
public:
    Renderer(const RendererType& renderer_type);
    ~Renderer();

private:
};