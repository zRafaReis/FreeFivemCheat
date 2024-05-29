#include <Windows.h>

#include <FrameWork/FrameWork.hpp>

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
#ifdef _DEBUG
	FrameWork::Misc::InitializeConsole();
#endif // _DEBUG

#ifdef _DEBUG
	FrameWork::Misc::ShutDownConsole();
#endif // _DEBUG
}