/**
Apr 8, 2018
Jay R Ravi
**/

#include <windows.h>
#include "application-win32.h"



int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    physika::ApplicationWin32 app(_T("Physika App Framework"), 1024, 768); 
    app.Initialize(); 
    app.Run(); 
    return 0; 
}




