#include <stdio.h>

#include "cube-app.h"

namespace cube {

CubeApp::CubeApp(TCHAR const* const title, int width, int height)
    : physika::Application(title, width, height)
{
}

void CubeApp::OnUpdate()
{
}

void CubeApp::OnResize(int /*width*/, int /*height*/)
{
}

void CubeApp::OnKeyUp(Keycode /*key*/)
{
}

void CubeApp::OnKeyDown(Keycode /*key*/)
{
}

void CubeApp::OnMouseUp(MouseButton /*button*/, int /*x*/, int /*y*/)
{
}

void CubeApp::OnMouseDown(MouseButton /*button*/, int /*x*/, int /*y*/)
{
}

void CubeApp::OnMouseMove(int /*x*/, int /*y*/)
{
}

void CubeApp::OnMouseWheel(int /*delta*/)
{
}

}  // namespace cube