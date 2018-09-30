/**
Apr 8, 2018
Jay R Ravi
**/

#include "app-framework/application.h"

int main()
{
    physika::Application app(_T("Physika App Framework"), 1024, 768); 
    app.Initialize(); 
    app.Run(); 
    return 0; 
}




