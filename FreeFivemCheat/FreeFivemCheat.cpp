#include <Windows.h>

#include <thread>

#include <Cheat/Cheat.hpp>
#include <FrameWork/FrameWork.hpp>

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
#ifdef _DEBUG
	FrameWork::Misc::InitializeConsole();
#endif // _DEBUG

	Cheat::Initialize();

	while (!g_Options.General.ShutDown)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

#ifdef _DEBUG
	FrameWork::Misc::ShutDownConsole();
#endif // _DEBUG
}