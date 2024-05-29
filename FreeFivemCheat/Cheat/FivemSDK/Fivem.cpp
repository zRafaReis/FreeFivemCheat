#include "Fivem.hpp"

namespace Cheat
{
	void FivemSDK::Intialize()
	{
		if (bIsIntialized)
			return;

		if (FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2060_GameProcess.exe")) || FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2060_GTAProcess.exe")))
		{
			Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2060_GameProcess.exe"));
			if (Pid)
			{
				GameVersion = GAME_VERSION_GAME_b2060;
				ModuleName = XorStr("FiveM_b2060_GameProcess.exe");
			}
			else
			{
				Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2060_GTAProcess.exe"));
				GameVersion = GAME_VERSION_GTA_b2060;
				ModuleName = XorStr("FiveM_b2060_GTAProcess.exe");
			}

			ModuleBase = FrameWork::Memory::GetModuleBaseByName(Pid, FrameWork::Misc::String2WString(ModuleName));
			if (ModuleBase)
			{
				World = ModuleBase + 0x24C8858;
				ReplayInterface = ModuleBase + 0x1EC3828;
				ViewPort = ModuleBase + 0x1F6A7E0;
				Camera = ModuleBase + 0x1F6B940;

				bIsIntialized = true;
			}
		}
		else if (FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2189_GameProcess.exe")) || FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2189_GTAProcess.exe")))
		{
			Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2189_GameProcess.exe"));
			if (Pid)
			{
				GameVersion = GAME_VERSION_GAME_b2189;
				ModuleName = XorStr("FiveM_b2189_GameProcess.exe");
			}
			else
			{
				Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2189_GTAProcess.exe"));
				GameVersion = GAME_VERSION_GTA_b2189;
				ModuleName = XorStr("FiveM_b2189_GTAProcess.exe");
			}

			ModuleBase = FrameWork::Memory::GetModuleBaseByName(Pid, FrameWork::Misc::String2WString(ModuleName));
			if (ModuleBase)
			{
				World = ModuleBase + 0x24E6D90;
				ReplayInterface = ModuleBase + 0x1EE18A8;
				ViewPort = ModuleBase + 0x1F888C0;
				Camera = ModuleBase + 0x1F89768;

				bIsIntialized = true;
			}
		}
		else if (FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2372_GameProcess.exe")) || FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2372_GTAProcess.exe")))
		{
			Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2372_GameProcess.exe"));
			if (Pid)
			{
				GameVersion = GAME_VERSION_GAME_b2372;
				ModuleName = XorStr("FiveM_b2372_GameProcess.exe");
			}
			else
			{
				Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2372_GTAProcess.exe"));
				GameVersion = GAME_VERSION_GTA_b2372;
				ModuleName = XorStr("FiveM_b2372_GTAProcess.exe");
			}

			ModuleBase = FrameWork::Memory::GetModuleBaseByName(Pid, FrameWork::Misc::String2WString(ModuleName));
			if (ModuleBase)
			{
				World = ModuleBase + 0x252DCD8;
				ReplayInterface = ModuleBase + 0x1F05208;
				ViewPort = ModuleBase + 0x1F9E9F0;
				Camera = ModuleBase + 0x1F9F898;

				bIsIntialized = true;
			}
		}
		else if (FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2545_GameProcess.exe")) || FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2545_GTAProcess.exe")))
		{
			Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2545_GameProcess.exe"));
			if (Pid)
			{
				GameVersion = GAME_VERSION_GAME_b2545;
				ModuleName = XorStr("FiveM_b2545_GameProcess.exe");
			}
			else
			{
				Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2545_GTAProcess.exe"));
				GameVersion = GAME_VERSION_GTA_b2545;
				ModuleName = XorStr("FiveM_b2545_GTAProcess.exe");
			}

			ModuleBase = FrameWork::Memory::GetModuleBaseByName(Pid, FrameWork::Misc::String2WString(ModuleName));
			if (ModuleBase)
			{
				World = ModuleBase + 0x25667E8;
				ReplayInterface = ModuleBase + 0x1F2E7A8;
				ViewPort = ModuleBase + 0x1FD6F70;
				Camera = ModuleBase + 0x1FD7E18;

				bIsIntialized = true;
			}
		}
		else if (FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2612_GameProcess.exe")) || FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2612_GTAProcess.exe")))
		{
			Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2612_GameProcess.exe"));
			if (Pid)
			{
				GameVersion = GAME_VERSION_GAME_b2612;
				ModuleName = XorStr("FiveM_b2612_GameProcess.exe");
			}
			else
			{
				Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2612_GTAProcess.exe"));
				GameVersion = GAME_VERSION_GTA_b2612;
				ModuleName = XorStr("FiveM_b2612_GTAProcess.exe");
			}

			ModuleBase = FrameWork::Memory::GetModuleBaseByName(Pid, FrameWork::Misc::String2WString(ModuleName));
			if (ModuleBase)
			{
				World = ModuleBase + 0x2567DB0;
				ReplayInterface = ModuleBase + 0x1F77EF0;
				ViewPort = ModuleBase + 0x1FD8570;
				Camera = ModuleBase + 0x1FD9418;

				bIsIntialized = true;
			}
		}
		else if (FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2699_GameProcess.exe")) || FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2699_GTAProcess.exe")))
		{
			Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2699_GameProcess.exe"));
			if (Pid)
			{
				GameVersion = GAME_VERSION_GAME_b2699;
				ModuleName = XorStr("FiveM_b2699_GameProcess.exe");
			}
			else
			{
				Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2699_GTAProcess.exe"));
				GameVersion = GAME_VERSION_GTA_b2699;
				ModuleName = XorStr("FiveM_b2699_GTAProcess.exe");
			}

			ModuleBase = FrameWork::Memory::GetModuleBaseByName(Pid, FrameWork::Misc::String2WString(ModuleName));
			if (ModuleBase)
			{
				World = ModuleBase + 0x26684D8;
				ReplayInterface = ModuleBase + 0x20304C8;
				ViewPort = ModuleBase + 0x20D8C90;
				Camera = ModuleBase + 0x20D9B38;

				bIsIntialized = true;
			}
		}
		else if (FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2802_GameProcess.exe")) || FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2802_GTAProcess.exe")))
		{
			Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2802_GameProcess.exe"));
			if (Pid)
			{
				GameVersion = GAME_VERSION_GAME_b2802;
				ModuleName = XorStr("FiveM_b2802_GameProcess.exe");
			}
			else
			{
				Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2802_GTAProcess.exe"));
				GameVersion = GAME_VERSION_GTA_b2802;
				ModuleName = XorStr("FiveM_b2802_GTAProcess.exe");
			}

			ModuleBase = FrameWork::Memory::GetModuleBaseByName(Pid, FrameWork::Misc::String2WString(ModuleName));
			if (ModuleBase)
			{
				World = ModuleBase + 0x254D448;
				ReplayInterface = ModuleBase + 0x1F5B820;
				ViewPort = ModuleBase + 0x1FBC100;
				Camera = ModuleBase + 0x1FBCFA8;

				bIsIntialized = true;
			}
		}
		else if (FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2944_GameProcess.exe")) || FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2944_GTAProcess.exe")))
		{
			Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2944_GameProcess.exe"));
			if (Pid)
			{
				GameVersion = GAME_VERSION_GAME_b2944;
				ModuleName = XorStr("FiveM_b2944_GameProcess.exe");
			}
			else
			{
				Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b2944_GTAProcess.exe"));
				GameVersion = GAME_VERSION_GTA_b2944;
				ModuleName = XorStr("FiveM_b2944_GTAProcess.exe");
			}

			ModuleBase = FrameWork::Memory::GetModuleBaseByName(Pid, FrameWork::Misc::String2WString(ModuleName));
			if (ModuleBase)
			{
				World = ModuleBase + 0x257BEA0;
				ReplayInterface = ModuleBase + 0x1F42068;
				ViewPort = ModuleBase + 0x1FEAAC0;
				Camera = ModuleBase + 0x1FEB968;

				bIsIntialized = true;
			}
		}
		else if (FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b3095_GameProcess.exe")) || FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b3095_GTAProcess.exe")))
		{
			Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b3095_GameProcess.exe"));
			if (Pid)
			{
				GameVersion = GAME_VERSION_GAME_b3095;
				ModuleName = XorStr("FiveM_b3095_GameProcess.exe");
			}
			else
			{
				Pid = FrameWork::Memory::GetProcessPidByName(XorStr(L"FiveM_b3095_GTAProcess.exe"));
				GameVersion = GAME_VERSION_GTA_b3095;
				ModuleName = XorStr("FiveM_b3095_GTAProcess.exe");
			}

			ModuleBase = FrameWork::Memory::GetModuleBaseByName(Pid, FrameWork::Misc::String2WString(ModuleName));
			if (ModuleBase)
			{
				World = ModuleBase + 0x2593320;
				ReplayInterface = ModuleBase + 0x1F58B58;
				ViewPort = ModuleBase + 0x20019E0;
				Camera = ModuleBase + 0x2002888;

				bIsIntialized = true;
			}
		}
	}
}