/**
Apr 8, 2018
Jay R Ravi
**/

#include <windows.h>
#include <tchar.h>



LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    TCHAR szWindowClass[] = _T("win32app"); 
    TCHAR szTitle[] = _T("Rendering Window"); 

    WNDCLASSEX wcex; 
    wcex.cbSize         = sizeof(WNDCLASSEX); 
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1); 
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    
    if (!RegisterClassEx(&wcex)) {
        MessageBox(NULL, _T("Call to RegisterClassEx failed"), _T("Error"), NULL);
        return 1; 
    }

    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        1024,
        768,
        NULL,
        NULL,
        hInstance,
        NULL,
        );

   

    if (!hWnd) {
        MessageBox(NULL, _T("Window Creation failed"), _T("Error"), NULL); 
        return 1; 
    }

    ShowWindow(hWnd, nCmdShow); 
    UpdateWindow(hWnd); 

    MSG msg; 

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    }

    return (int)msg.wParam; 
}




LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

    return 0; 
}