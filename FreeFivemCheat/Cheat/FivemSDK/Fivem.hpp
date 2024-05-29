#pragma once
#include <cstdint>

#include "Classes.hpp"

#include <FrameWork/FrameWork.hpp>

namespace Cheat
{
	enum eGAME_VERSION
	{
		GAME_VERSION_GAME_b2060,
		GAME_VERSION_GTA_b2060,
		GAME_VERSION_GAME_b2189,
		GAME_VERSION_GTA_b2189,
		GAME_VERSION_GAME_b2372,
		GAME_VERSION_GTA_b2372,
		GAME_VERSION_GAME_b2545,
		GAME_VERSION_GTA_b2545,
		GAME_VERSION_GAME_b2612,
		GAME_VERSION_GTA_b2612,
		GAME_VERSION_GAME_b2699,
		GAME_VERSION_GTA_b2699,
		GAME_VERSION_GAME_b2802,
		GAME_VERSION_GTA_b2802,
		GAME_VERSION_GAME_b2944,
		GAME_VERSION_GTA_b2944,
		GAME_VERSION_GAME_b3095,
		GAME_VERSION_GTA_b3095,
	};

	class FivemSDK
	{
	public:
		void Intialize();
		void UpdateEntities();

		DWORD GetPid() { return Pid; }
		uint64_t GetModuleBase() { return ModuleBase; };
		std::string GetModuleName() { return ModuleName; };
		bool HasAdehsive() { return ((int)GameVersion % 2) != 0; }

		void UpdateNamesThread();
		nlohmann::json GetServerInfo();

		bool IsInitialized() { return bIsIntialized; }

	private:
		bool bIsIntialized = false;

		uint64_t World; // 48 8B 05 ? ? ? ? 33 D2 48 8B 40 08 8A CA 48 85 C0 74 16 48 8B
		uint64_t ReplayInterface; // 48 8D 0D ?? ?? ?? ?? 48 ?? ?? E8 ?? ?? ?? ?? 48 8D 0D ?? ?? ?? ?? 8A D8 E8 ?? ?? ?? ?? 84 DB 75 13 48 8D 0D ?? ?? ?? ?? 48 8B D7 E8 ?? ?? ?? ?? 84 C0 74 BC 8B 8F
		uint64_t ViewPort; // 48 8B 15 ? ? ? ? 48 8D 2D ? ? ? ? 48 8B CD
		uint64_t Camera; // 48 8B 05 ? ? ? ? 38 98 ? ? ? ? 8A C3

		DWORD Pid;
		uint64_t ModuleBase;
		std::string ModuleName;
		std::string FivemFolder;
		std::string CrashoMetryLocation;
		std::string ServerIp;
		std::string ServerPort;
		nlohmann::json PlayersInfo;
		std::unordered_map<int, std::string> PlayerIdToName;
		bool LanGame;
		eGAME_VERSION GameVersion;

	private:
		CWorld* pWorld;
		CPed* pLocalPlayer;
		CReplayInterface* pReplayInterface;
		CPedInterface* pPedInterface;
		CCamGameplayDirector* pCamGameplayDirector;

		uint64_t pViewPort;
	};

	inline FivemSDK g_Fivem;
}