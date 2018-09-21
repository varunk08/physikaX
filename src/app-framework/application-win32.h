#pragma once

#include <Windows.h>
#include <tchar.h>

namespace physika {

class ApplicationWin32
{
public: 
    ApplicationWin32(TCHAR const* const title, int width, int height); 
    
    bool Initialize();
    void Shutdown();
    void Run();

    virtual void OnUpdate();
    virtual void OnResize();
    virtual void OnKeyUp();
    virtual void OnKeyDown();
    virtual void OnMouseUp();
    virtual void OnMouseMove();
    virtual void OnMouseWheel();
    virtual void OnMouseDown();

    LRESULT CALLBACK HandleEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
private:
    
    TCHAR const* mWindowTitle; 
    int mWidth; 
    int mHeight; 
    HINSTANCE mHinstance;
    HWND mHwnd;
};

} // namespace physika
