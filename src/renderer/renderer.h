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
    virtual void init() = 0;
    virtual void init_geometry();
    virtual void init_scene();
    virtual void init_camera();
    virtual void draw_frame();

    virtual ~Renderer();

protected:
    Renderer();
};