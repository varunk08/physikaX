#pragma once

#include <Windows.h>
#include <tchar.h>

#include "app-framework/input.h"

namespace physika {

class ApplicationWin32
{
public: 
    ApplicationWin32(TCHAR const* const title, int width, int height); 
    
    bool Initialize();
    void Shutdown();
    void Run();

    virtual void OnUpdate();
    virtual void OnResize(int width, int height);
    virtual void OnKeyUp(Keycode key);
    virtual void OnKeyDown(Keycode key);
    virtual void OnMouseUp(MouseButton button, int x, int y);
    virtual void OnMouseDown(MouseButton button, int x, int y);
    virtual void OnMouseMove(int x, int y);
    virtual void OnMouseWheel(int delta);
    
private:
    int mWidth; 
    int mHeight; 
    TCHAR const* mWindowTitle;

    //! OS Specific
    HWND mHwnd;
    HINSTANCE mHinstance;
};

} // namespace physika
