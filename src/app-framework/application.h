#pragma once

#ifdef _WIN32
#include "application-win32.h"
namespace physika {
typedef ApplicationWin32 Application;
}
#endif 