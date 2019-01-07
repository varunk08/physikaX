/**
Jan 7, 2019
Jay R Ravi
**/

#include <stdio.h>
#include "cube-app.h"

int main()
{
    cube::CubeApp app(_T("DX11 Cube"), 1024, 768);

    if (!app.Initialize()) {
        printf("Could not initialize app. Exiting");
        return 1;
    }
    app.Run();

    if (!app.Shutdown()) {
        printf("Shutdown sequence failed.");
        return 1;
    }
    return 0;
}
