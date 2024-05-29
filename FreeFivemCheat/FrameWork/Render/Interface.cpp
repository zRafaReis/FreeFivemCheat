#include "Interface.hpp"
#include <Cheat/Options.hpp>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

bool LeftMouseDown = false;
ImVec2 LastMousePos = ImVec2(0, 0);
ImRect WindowRect = ImRect();

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

		ImGuiStyle* Style = &ImGui::GetStyle();

		Style->WindowRounding = 5;

		ImGuiIO& io = ImGui::GetIO();
		io.WantSaveIniSettings = false;
		io.IniFilename = nullptr;
		io.LogFilename = nullptr;
	}

	void Interface::RenderGui()
	{
		if (!bIsMenuOpen)
			return;

		HandleWindowDrag();

		ImGui::SetNextWindowSize(ImVec2(450, 250));
		ImGui::Begin(XorStr("Free FiveM Cheat"), &bIsMenuOpen, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
		{
			ImVec2 WindowPos = ImGui::GetWindowPos();
			ImVec2 WindowSize = ImGui::GetWindowSize();

			WindowRect = ImRect(WindowPos, WindowPos + WindowSize);

			ImGui::BeginTabBar(XorStr("MainTabs"));
			{
				if (ImGui::BeginTabItem(XorStr("Aimbot")))
				{
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem(XorStr("ESP")))
				{
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem(XorStr("Misc")))
				{
					ImGui::EndTabItem();
				}
				if (ImGui::BeginTabItem(XorStr("General")))
				{
					ImGui::SliderInt(XorStr("Thread Delay"), &g_Options.General.ThreadDelay, 0, 100, XorStr("%d ms"));
					if (ImGui::Button(XorStr("ShutDown")))
						g_Options.General.ShutDown = true;

					ImGui::EndTabItem();
				}
			}
			ImGui::EndTabBar();
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

	void Interface::HandleWindowDrag()
	{
		if (ImGui::IsMouseDown(ImGuiMouseButton_Left))
		{
			if (!LeftMouseDown)
				LastMousePos = ImGui::GetMousePos();

			LeftMouseDown = true;
		}
		else
		{
			LeftMouseDown = false;
		}

		ImVec2 CurrentMousePos = ImGui::GetMousePos();

		if (CurrentMousePos.x != LastMousePos.x || CurrentMousePos.y != LastMousePos.y)
		{
			if (LeftMouseDown)
			{
				if (WindowRect.Contains(CurrentMousePos))
				{
					ImVec2 Delta = CurrentMousePos - LastMousePos;
					ImVec2 Min = ImVec2(0, 0);
					ImVec2 Max = ImGui::GetIO().DisplaySize - WindowRect.GetSize();
					ImVec2 Pos = ImClamp(WindowRect.Min + Delta, Min, Max);
					WindowRect.Min = Pos;
					LastMousePos = CurrentMousePos;
				}
			}
		}

		ImGui::SetNextWindowPos(WindowRect.Min);
		ImGui::SetNextWindowSize(WindowRect.GetSize());
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