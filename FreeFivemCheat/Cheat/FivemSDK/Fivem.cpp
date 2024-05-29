#include "Fivem.hpp"

#include <fstream>
#include <filesystem>
#include <thread>

#include "../Cheat.hpp"

namespace Cheat
{
	uint64_t Offsets::EntityType;
	uint64_t Offsets::PlayerInfo;
	uint64_t Offsets::WeaponManager;
	uint64_t Offsets::PlayerNetID;

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

				Offsets::EntityType = 0x10B8;
				Offsets::PlayerInfo = 0x10A8;
				Offsets::WeaponManager = 0x10D8;
				Offsets::PlayerNetID = 0x78;

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

				Offsets::EntityType = 0x10B8;
				Offsets::PlayerInfo = 0x10C8;
				Offsets::WeaponManager = 0x10D8;
				Offsets::PlayerNetID = 0x78;

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

				Offsets::EntityType = 0x10B8;
				Offsets::PlayerInfo = 0x10C8;
				Offsets::WeaponManager = 0x10D8;
				Offsets::PlayerNetID = 0x88;

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

				Offsets::EntityType = 0x10B8;
				Offsets::PlayerInfo = 0x10A8;
				Offsets::WeaponManager = 0x10D8;
				Offsets::PlayerNetID = 0x88;

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

				Offsets::EntityType = 0x10B8;
				Offsets::PlayerInfo = 0x10C8;
				Offsets::WeaponManager = 0x10D8;
				Offsets::PlayerNetID = 0x88;

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

				Offsets::EntityType = 0x10B8;
				Offsets::PlayerInfo = 0x10C8;
				Offsets::WeaponManager = 0x10D8;
				Offsets::PlayerNetID = 0x88;

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

				Offsets::EntityType = 0x1098;
				Offsets::PlayerInfo = 0x10A8;
				Offsets::WeaponManager = 0x10B8;
				Offsets::PlayerNetID = 0x88;

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

				Offsets::EntityType = 0x1098;
				Offsets::PlayerInfo = 0x10A8;
				Offsets::WeaponManager = 0x10B8;
				Offsets::PlayerNetID = 0xE8;

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

				Offsets::EntityType = 0x1098;
				Offsets::PlayerInfo = 0x10A8;
				Offsets::WeaponManager = 0x10B8;
				Offsets::PlayerNetID = 0xE8;

				bIsIntialized = true;
			}
		}

		if (bIsIntialized)
			FrameWork::Memory::AttachProces(Pid);
	}

	void FivemSDK::UpdateEntities()
	{
		if (!pWorld)
		{
			pWorld = (CWorld*)FrameWork::Memory::ReadMemory<uint64_t>(World);

			if (!pWorld)
				return;

#ifdef _DEBUG
			std::cout << XorStr("[FivemSDK] World: 0x") << std::hex << std::uppercase << pWorld << std::endl;
#endif // _DEBUG
		}

		pLocalPlayer = pWorld->LocalPlayer();

		if (!pLocalPlayer)
			return;

#ifdef _DEBUG
		static bool Logged = false;
		if (!Logged)
		{
			std::cout << XorStr("[FivemSDK] LocalPlayer: 0x") << std::hex << std::uppercase << pLocalPlayer << std::endl;
			Logged = true;
		}
#endif // _DEBUG

		if (!pReplayInterface)
		{
			pReplayInterface = (CReplayInterface*)FrameWork::Memory::ReadMemory<uint64_t>(ReplayInterface);

			if (!pReplayInterface)
				return;

#ifdef _DEBUG
			std::cout << XorStr("[FivemSDK] ReplayInterface: 0x") << std::hex << std::uppercase << pReplayInterface << std::endl;
#endif // _DEBUG
		}

		if (!pPedInterface)
		{
			pPedInterface = pReplayInterface->PedInterface();

			if (!pPedInterface)
				return;

#ifdef _DEBUG
			std::cout << XorStr("[FivemSDK] PedInterface: 0x") << std::hex << std::uppercase << pPedInterface << std::endl;
#endif // _DEBUG
		}

		if (!pCamGameplayDirector)
		{
			pCamGameplayDirector = (CCamGameplayDirector*)FrameWork::Memory::ReadMemory<uint64_t>(Camera);

			if (!pCamGameplayDirector)
				return;

#ifdef _DEBUG
			std::cout << XorStr("[FivemSDK] CamGameplayDirector: 0x") << std::hex << std::uppercase << pCamGameplayDirector << std::endl;
#endif // _DEBUG
		}

		LockList.lock();

		EntityList.clear();
		EntityList.shrink_to_fit();

		for (size_t i = 0; i < pPedInterface->PedsAtList(); i++)
		{
			CPed* Ped = pPedInterface->PedList()->Ped(i);

			if (!Ped)
				continue;

			if (Ped->GetHealth() <= 0)
				continue;

			if (CachedStaticInfoList.find(Ped) == CachedStaticInfoList.end())
			{
				PedStaticInfo StaticInfo;
				{
					StaticInfo.Ped = Ped;
					StaticInfo.iIndex = i;
					StaticInfo.bIsLocalPlayer = (Ped == pLocalPlayer);
					StaticInfo.bIsNPC = Ped->IsNPC();

					if (StaticInfo.bIsNPC || LanGame)
					{
						StaticInfo.NetId = -1;
					}
					else
					{
						StaticInfo.NetId = Ped->GetPlayerInfo()->GetPlayerID();
					}
				}

				CachedStaticInfoList[Ped] = StaticInfo;
			}

			Entity CurrentEntity;
			CurrentEntity.StaticInfo = CachedStaticInfoList[Ped];

			if (CurrentEntity.StaticInfo.Name.empty())
			{
				if (CurrentEntity.StaticInfo.bIsNPC)
				{
					CurrentEntity.StaticInfo.Name = XorStr("NPC");
				}

				if (!PlayersInfo.empty() && !PlayerIdToName.empty())
				{
					auto it = PlayerIdToName.find(CurrentEntity.StaticInfo.NetId);
					if (it != PlayerIdToName.end() && CurrentEntity.StaticInfo.NetId != -1)
					{
						CurrentEntity.StaticInfo.Name = it->second;
					}
					else
					{
						CurrentEntity.StaticInfo.Name = XorStr("username");
					}
				}
			}

			CurrentEntity.Cordinates = Ped->GetCoordinate();

			if (CurrentEntity.StaticInfo.bIsLocalPlayer)
			{
				LocalPlayerInfo.Ped = Ped;

				LocalPlayerInfo.iIndex = i;
				LocalPlayerInfo.WorldPos = CurrentEntity.Cordinates;
				LocalPlayerInfo.ScreenPos = WorldToScreen(CurrentEntity.Cordinates);
			}

			EntityList.push_back(CurrentEntity);
		}

		LockList.unlock();

		if (ServerIp.empty() && !LanGame)
		{
			if (FivemFolder.empty() || CrashoMetryLocation.empty())
			{
				HKEY hKey;
				WCHAR Buffer[MAX_PATH];
				DWORD BufferSize = sizeof(Buffer);
				if (SafeCall(RegOpenKeyEx)(HKEY_CURRENT_USER, XorStr(L"SOFTWARE\\CitizenFX\\FiveM"), 0, KEY_READ, &hKey) == ERROR_SUCCESS)
				{
					if (RegQueryValueEx(hKey, XorStr(L"Last Run Location"), NULL, NULL, (LPBYTE)Buffer, &BufferSize) == ERROR_SUCCESS)
					{
						std::string CrashoMetryPath = FrameWork::Misc::Wstring2String(std::wstring(Buffer)) + XorStr("data\\cache\\crashometry");
						if (std::filesystem::exists(CrashoMetryPath))
						{
							FivemFolder = FrameWork::Misc::Wstring2String(std::wstring(Buffer));
							CrashoMetryLocation = CrashoMetryPath;
						}
					}

					SafeCall(RegCloseKey)(hKey);
				}
			}

			if (!CrashoMetryLocation.empty() || ServerIp.empty())
			{
				std::ifstream Crashometry(CrashoMetryLocation);
				std::string Line1;

				if (Crashometry.is_open())
				{
					if (std::getline(Crashometry, Line1))
					{
						size_t StartPos = Line1.find(XorStr("last_server_url"));
						if (StartPos != std::string::npos)
						{
							std::string TempServerIp = Line1.substr(StartPos + 15);

							StartPos = TempServerIp.find(XorStr("last_server"));

							TempServerIp = TempServerIp.substr(StartPos + 11);

							StartPos = TempServerIp.find(XorStr(":"));

							ServerIp = TempServerIp.substr(0, StartPos);
							ServerPort = TempServerIp.substr(StartPos + 1, TempServerIp.find(XorStr("")) - StartPos - 1);
						}
					}

					Crashometry.close();
				}
			}

			if (ServerIp.empty() || ServerPort.empty())
			{
				LanGame = true;

#ifdef _DEBUG
				std::cout << XorStr("[FivemSDK] Lan Game.") << std::endl;
#endif // _DEBUG
			}
			else
			{
#ifdef _DEBUG
				std::cout << XorStr("[FivemSDK] Server IP: ") << ServerIp << XorStr(":") << ServerPort << std::endl;
#endif // _DEBUG

				std::thread([&]() { this->UpdateNamesThread(); }).detach();
			}
		}
	}

	ImVec2 FivemSDK::WorldToScreen(Vector3D Pos)
	{
		if (!pViewPort)
		{
			pViewPort = FrameWork::Memory::ReadMemory<uint64_t>(ViewPort);
			if (!pViewPort)
				return ImVec2(0, 0);
		}

		Matrix4x4 ViewMatrix = FrameWork::Memory::ReadMemory<Matrix4x4>(pViewPort + 0x24C);

		ViewMatrix.TransposeThisMatrix();

		Vector4D VecX(ViewMatrix._21, ViewMatrix._22, ViewMatrix._23, ViewMatrix._24);
		Vector4D VecY(ViewMatrix._31, ViewMatrix._32, ViewMatrix._33, ViewMatrix._34);
		Vector4D VecZ(ViewMatrix._41, ViewMatrix._42, ViewMatrix._43, ViewMatrix._44);

		Vector3D ScreenPos;
		ScreenPos.x = (VecX.x * Pos.x) + (VecX.y * Pos.y) + (VecX.z * Pos.z) + VecX.w;
		ScreenPos.y = (VecY.x * Pos.x) + (VecY.y * Pos.y) + (VecY.z * Pos.z) + VecY.w;
		ScreenPos.z = (VecZ.x * Pos.x) + (VecZ.y * Pos.y) + (VecZ.z * Pos.z) + VecZ.w;

		if (ScreenPos.z <= 0.1f)
			return ImVec2(0, 0);

		ScreenPos.z = 1.0f / ScreenPos.z;
		ScreenPos.x *= ScreenPos.z;
		ScreenPos.y *= ScreenPos.z;

		ScreenPos.x += ImGui::GetIO().DisplaySize.x / 2 + float(0.5f * ScreenPos.x * ImGui::GetIO().DisplaySize.x + 0.5f);
		ScreenPos.y = ImGui::GetIO().DisplaySize.y / 2 - float(0.5f * ScreenPos.y * ImGui::GetIO().DisplaySize.y + 0.5f);

		return ImVec2(ScreenPos.x, ScreenPos.y);
	}

	bool FivemSDK::IsOnScreen(ImVec2 Pos)
	{
		if (Pos.x < 0.1f || Pos.y < 0.1 || Pos.x > ImGui::GetIO().DisplaySize.x || Pos.y > ImGui::GetIO().DisplaySize.y)
			return false;

		return true;
	}

	void FivemSDK::UpdateNamesThread()
	{
		while (!g_Options.General.ShutDown)
		{
			if (ServerIp.size() > 5 && ServerPort.size() > 2)
			{
				PlayersInfo = GetServerInfo();

				for (const auto& Player : PlayersInfo)
				{
					PlayerIdToName[Player[XorStr("id")]] = Player[XorStr("name")];
				}

#ifdef _DEBUG
				std::cout << XorStr("[FivemSDK] Found Players Infos, Connected Players: ") << std::dec << PlayerIdToName.size() << std::endl;
#endif // _DEBUG

				std::this_thread::sleep_for(std::chrono::seconds(10));
			}

			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}

	nlohmann::json FivemSDK::GetServerInfo()
	{
		if (!ServerIp.empty())
		{
			std::string RawServerInfo = FrameWork::Misc::DownloadServerInfo(FrameWork::Misc::String2WString(ServerIp), std::atoi(ServerPort.c_str()));

			return nlohmann::json::parse(RawServerInfo);
		}

		return NULL;
	}
}