#include "../renderer.h"
#include <iostream>

class VkRenderer : public Renderer {
public:
    VkRenderer();
    void init() override ;
    void init_geometry() override ;
    void init_scene() override ;
    void init_camera() override ;
    void draw_frame() override ;

private:  
};