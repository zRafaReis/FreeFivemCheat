#pragma once

#include <FrameWork/FrameWork.hpp>

namespace FrameWork
{
	namespace Memory
	{
		HWND GetWindowHandleByPID(DWORD Pid);
		HWND GetWindowHandleByName(std::wstring WindowName);
		DWORD GetProcessPidByName(std::wstring ProcessName);
		uint64_t GetModuleBaseByName(DWORD Pid, std::wstring ModuleName);
	}
}