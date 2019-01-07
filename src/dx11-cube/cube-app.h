#pragma once

#include "app-framework/application.h"
#include "app-framework/input.h"

namespace cube {

using physika::Keycode;
using physika::MouseButton;

class CubeApp : public physika::Application
{
public:
    CubeApp(TCHAR const* const title, int width, int height);
    void OnUpdate() override;
    void OnResize(int width, int height) override;
    void OnKeyUp(Keycode key) override;
    void OnKeyDown(Keycode key) override;
    void OnMouseUp(MouseButton button, int x, int y) override;
    void OnMouseDown(MouseButton button, int x, int y) override;
    void OnMouseMove(int x, int y) override;
    void OnMouseWheel(int delta) override;
};

}  // namespace cube
