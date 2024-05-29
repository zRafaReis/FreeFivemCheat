#include "Cheat.hpp"

#include "FivemSDK/Fivem.hpp"

#include <thread>
#include <FrameWork/FrameWork.hpp>
#include "Options.hpp"

namespace Cheat
{
	void Initialize()
	{
		while (!g_Fivem.IsInitialized())
		{
#ifdef _DEBUG
			std::cout << XorStr("[FiveM-Cheat] Searching for Fivem!") << std::endl;
#endif // _DEBUG

			g_Fivem.Intialize();

			if (!g_Fivem.IsInitialized())
				std::this_thread::sleep_for(std::chrono::seconds(5));
		}

#ifdef _DEBUG
		std::cout << XorStr("[FiveM-Cheat] Pid: ") << g_Fivem.GetPid() << XorStr(" | Name: ") << g_Fivem.GetModuleName() << XorStr(" | Base: 0x") << std::hex << g_Fivem.GetModuleBase() << XorStr(" | Adehsive: ") << g_Fivem.HasAdehsive() << std::endl;
#endif // _DEBUG

		FrameWork::Overlay::Setup(g_Fivem.GetPid());
		FrameWork::Overlay::Initialize();

		if (FrameWork::Overlay::IsInitialized())
		{
			FrameWork::Interface Interface(FrameWork::Overlay::GetOverlayWindow(), FrameWork::Overlay::GetTargetWindow(), FrameWork::Overlay::dxGetDevice(), FrameWork::Overlay::dxGetDeviceContext());
			Interface.UpdateStyle();
			FrameWork::Overlay::SetupWindowProcHook(std::bind(&FrameWork::Interface::WindowProc, &Interface, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

			MSG Message;
			ZeroMemory(&Message, sizeof(Message));
			while (Message.message != WM_QUIT)
			{
				if (PeekMessage(&Message, FrameWork::Overlay::GetOverlayWindow(), NULL, NULL, PM_REMOVE))
				{
					TranslateMessage(&Message);
					DispatchMessage(&Message);
				}

				ImGui::GetIO().MouseDrawCursor = Interface.GetMenuOpen();

				g_Fivem.UpdateEntities();

				if (Interface.ResizeHeight != 0 || Interface.ResizeWidht != 0)
				{
					FrameWork::Overlay::dxCleanupRenderTarget();
					FrameWork::Overlay::dxGetSwapChain()->ResizeBuffers(0, Interface.ResizeWidht, Interface.ResizeHeight, DXGI_FORMAT_UNKNOWN, 0);
					Interface.ResizeHeight = Interface.ResizeWidht = 0;
					FrameWork::Overlay::dxCreateRenderTarget();
				}

				Interface.HandleMenuKey();
				FrameWork::Overlay::UpdateWindowPos();
				 
				ImGui_ImplDX11_NewFrame();
				ImGui_ImplWin32_NewFrame();
				ImGui::NewFrame();
				{
					Interface.RenderGui();
				}
				ImGui::EndFrame();
				ImGui::Render();

				FrameWork::Overlay::dxRefresh();
				ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
				FrameWork::Overlay::dxGetSwapChain()->Present(0, 0);

				if (g_Options.General.ShutDown)
					return;

				std::this_thread::sleep_for(std::chrono::milliseconds(1 + g_Options.General.ThreadDelay));
			}
		}
	}

	void ShutDown()
	{
		if (!g_Options.General.ShutDown)
			return;

		FrameWork::Overlay::ShutDown();
		FrameWork::Overlay::dxShutDown();

		FrameWork::Memory::DetachProcess();
	}
}