#pragma once

#include "app-framework/input.h"
#include "app-framework/application.h"


namespace example {

using physika::MouseButton; 
using physika::Keycode;

class ExampleApp: public physika::Application
{
public: 
    ExampleApp(TCHAR const* const title, int width, int height);
    void OnUpdate() override;
    void OnResize(int width, int height) override;
    void OnKeyUp(Keycode key) override;
    void OnKeyDown(Keycode key) override;
    void OnMouseUp(MouseButton button, int x, int y) override;
    void OnMouseDown(MouseButton button, int x, int y) override;
    void OnMouseMove(int x, int y) override;
    void OnMouseWheel(int delta) override;
};

} //! namespace example
