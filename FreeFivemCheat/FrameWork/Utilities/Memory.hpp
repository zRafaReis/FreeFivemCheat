#pragma once

#include <FrameWork/FrameWork.hpp>

namespace FrameWork
{
	namespace Memory
	{
		HWND GetWindowHandleByPID(int Pid);
		HWND GetWindowHandleByName(std::wstring WindowName);
		DWORD GetProcessPidByName(std::wstring ProcessName);
	}
}