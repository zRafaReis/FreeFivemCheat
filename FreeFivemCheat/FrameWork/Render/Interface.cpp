#include "Interface.hpp"
#include <Cheat/Options.hpp>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace FrameWork
{
	void Interface::Initialize(HWND Window, HWND TargetWindow, ID3D11Device* Device, ID3D11DeviceContext* DeviceContext)
	{
		hWindow = Window;
		IDevice = Device;

		ImGui::CreateContext();
		ImGui_ImplWin32_Init(hWindow);
		ImGui_ImplDX11_Init(Device, DeviceContext);
	}

	void Interface::UpdateStyle()
	{
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.WantSaveIniSettings = false;
		io.IniFilename = nullptr;
		io.LogFilename = nullptr;
	}

	void Interface::RenderGui()
	{
		if (!bIsMenuOpen)
			return;

		ImGui::Begin(XorStr("Free FiveM Cheat"), &bIsMenuOpen);
		{
			if (ImGui::Button(XorStr("ShutDown")))
				g_Options.General.ShutDown = true;
		}
		ImGui::End();
	}

	void Interface::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_SIZE:
			if (wParam != SIZE_MINIMIZED)
			{
				ResizeWidht = (UINT)LOWORD(lParam);
				ResizeHeight = (UINT)HIWORD(lParam);
			}
			break;
		}

		if (bIsMenuOpen)
		{
			ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
		}
	}

	void Interface::HandleMenuKey()
	{
		static bool MenuKeyDown = false;
		if (GetAsyncKeyState(g_Options.General.MenuKey) & 0x8000)
		{
			if (!MenuKeyDown)
			{
				MenuKeyDown = true;
				bIsMenuOpen = !bIsMenuOpen;

				if (bIsMenuOpen)
				{
					SetWindowLong(hWindow, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_TRANSPARENT);
					SetForegroundWindow(hWindow);
				}
				else
				{
					SetWindowLong(hWindow, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_TRANSPARENT | WS_EX_LAYERED);
					SetForegroundWindow(hTargetWindow);
				}
			}
		}
		else
		{
			MenuKeyDown = false;
		}
	}

	void Interface::ShutDown()
	{
		ImGui_ImplDX11_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();
	}
}