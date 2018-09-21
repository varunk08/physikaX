
#include <windows.h>

#include "application-win32.h"

namespace {

physika::ApplicationWin32* sApp = nullptr; 

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return sApp->HandleEvent(hWnd, message, wParam, lParam);
}

} //namespace anonymous

using namespace physika;

ApplicationWin32::ApplicationWin32(TCHAR const* const title, int width, int height):
    mWindowTitle(title), mWidth(width), mHeight(height)
{ 
}

bool ApplicationWin32::Initialize()
{
    mHinstance = GetModuleHandle(nullptr); 
    TCHAR szWindowClass[] = _T("win32app");
    
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = mHinstance;
    wcex.hIcon = LoadIcon(nullptr, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));


    if (!RegisterClassEx(&wcex)) {
        MessageBox(NULL, _T("Call to RegisterClassEx failed"), _T("Error"), NULL);
        return false;
    }
    
    mHwnd = CreateWindow(
        szWindowClass,
        mWindowTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        mWidth,
        mHeight,
        NULL,
        NULL,
        mHinstance,
        NULL,
        );


    if (!mHwnd) {
        MessageBox(NULL, _T("Window Creation failed"), _T("Error"), NULL);
        return 1;
    }

    ShowWindow(mHwnd, SW_SHOW);
    UpdateWindow(mHwnd);

    return true; 
}

void physika::ApplicationWin32::Shutdown()
{
}

void ApplicationWin32::Run()
{
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void physika::ApplicationWin32::OnUpdate()
{
}

void physika::ApplicationWin32::OnResize()
{
}

void physika::ApplicationWin32::OnKeyUp()
{
}

void physika::ApplicationWin32::OnKeyDown()
{
}

void physika::ApplicationWin32::OnMouseUp()
{
}

void physika::ApplicationWin32::OnMouseMove()
{
}

void physika::ApplicationWin32::OnMouseWheel()
{
}

void physika::ApplicationWin32::OnMouseDown()
{
}

LRESULT physika::ApplicationWin32::HandleEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_PAINT:
        break;
    case WM_KEYUP:
        break;
    case WM_KEYDOWN:
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return LRESULT();
}

