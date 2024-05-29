#include "Memory.hpp"

struct TGetWindowHandleData
{
	DWORD Pid;
	std::wstring WindowName;
	HWND hWnd;
};

BOOL CALLBACK EnumWindowsCallback(HWND Handle, LPARAM lParam)
{
	TGetWindowHandleData& Data = *(TGetWindowHandleData*)lParam;

	// Searching For Name
	if (Data.Pid == 0)
	{
		int Length = SafeCall(GetWindowTextLength)(Handle);
		if (Length == 0)
			return true;

		std::wstring Buffer(Length + 1, L'\0');

		SafeCall(GetWindowText)(Handle, &Buffer[0], Length + 1);

		if (Data.WindowName != Buffer)
			return true;

		Data.hWnd = Handle;
		return false;
	}
	else // Searching for Pid
	{
		DWORD Pid;
		SafeCall(GetWindowThreadProcessId)(Handle, &Pid);

		if (Data.Pid != Pid)
			return true;

		Data.hWnd = Handle;
		return false;
	}

	return true;
}

namespace FrameWork
{
	HWND Memory::GetWindowHandleByPID(int Pid)
	{
		TGetWindowHandleData HandleData;
		HandleData.Pid = Pid;
		HandleData.WindowName = XorStr(L"");
		HandleData.hWnd = NULL;

		SafeCall(EnumWindows)(EnumWindowsCallback, (LPARAM)&HandleData);
		return HandleData.hWnd;
	}

	HWND Memory::GetWindowHandleByName(std::wstring WindowName)
	{
		TGetWindowHandleData HandleData;
		HandleData.Pid = 0;
		HandleData.WindowName = WindowName;
		HandleData.hWnd = NULL;

		SafeCall(EnumWindows)(EnumWindowsCallback, (LPARAM)&HandleData);
		return HandleData.hWnd;
	}

	DWORD Memory::GetProcessPidByName(std::wstring ProcessName)
	{
		HANDLE hSnapshot = SafeCall(CreateToolhelp32Snapshot)(TH32CS_SNAPPROCESS, 0);
		if (!hSnapshot || hSnapshot == INVALID_HANDLE_VALUE || hSnapshot == ((HANDLE)(LONG_PTR)ERROR_BAD_LENGTH))
		{
#ifdef _DEBUG
			std::cout << XorStr("[ERROR : FrameWork::Memory::GetProcessPidByName::CreateToolhelp32Snapshot] Error:") << SafeCall(GetLastError)() <<  std::endl;
#endif // _DEBUG
			return 0;
		}

		DWORD Pid;
		PROCESSENTRY32 ProcessEntry;
		ProcessEntry.dwSize = sizeof(ProcessEntry);
		if (SafeCall(Process32First)(hSnapshot, &ProcessEntry))
		{
			while (_wcsicmp(ProcessEntry.szExeFile, ProcessName.c_str()))
			{
				if (!SafeCall(Process32Next)(hSnapshot, &ProcessEntry)) // Copy The Next Process of the Snapshot and Paste at PROCESSENTRY32 Struct And Check if The Function Worked
				{
					SafeCall(CloseHandle)(hSnapshot);
					return 0;
				}
			}

			Pid = ProcessEntry.th32ProcessID; // Found
		}
		else
		{
#ifdef _DEBUG
			std::cout << XorStr("[ERROR : FrameWork::Memory::GetProcessPidByName::Process32First] Error:") << SafeCall(GetLastError)() << std::endl;
#endif // _DEBUG
			SafeCall(CloseHandle)(hSnapshot);
			return 0;
		}

		SafeCall(CloseHandle)(hSnapshot);
		return Pid;
	}
}