#pragma once
#include <iostream>

enum RendererType:uint32_t {
    VULKAN = 0,
    OPENGL,
    DX12
};

class Renderer {
public:
    static Renderer* CreateRenderer(const RendererType& renderer_type);
    virtual void Init() = 0;

    ~Renderer();

protected:
    Renderer();
};