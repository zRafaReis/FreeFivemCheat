#pragma once

#include "Offsets.hpp"

#include <FrameWork/FrameWork.hpp>

namespace Cheat
{
	class CPlayerInfo
	{
	public:
		int GetPlayerID()
		{
			if (!this)
				return 0;

			return FrameWork::Memory::ReadMemory<int>(this + Offsets::PlayerNetID);
		}
	};

	class CWeaponInfo
	{
	public:
		std::string GetWeaponName()
		{
			if (!this)
				return XorStr("");

			return FrameWork::Memory::ReadProcessMemoryString(FrameWork::Memory::ReadMemory<uint64_t>(this + 0x05F0));
		}
	};

	class CWeaponManager
	{
	public:
		CWeaponInfo* GetWeaponInfo()
		{
			if (!this)
				return 0;

			return (CWeaponInfo*)FrameWork::Memory::ReadMemory<uint64_t>(this + 0x20);
		}
	};

	class CPed
	{
	public:
		CPlayerInfo* GetPlayerInfo()
		{
			if (!this)
				return 0;

			return (CPlayerInfo*)FrameWork::Memory::ReadMemory<uint64_t>(this + Offsets::PlayerInfo);
		}

		CWeaponManager* GetWeaponManager()
		{
			if (!this)
				return 0;

			return (CWeaponManager*)FrameWork::Memory::ReadMemory<uint64_t>(this + Offsets::WeaponManager);
		}

		Vector3D GetCoordinate()
		{
			if (!this)
				return Vector3D{ 0,0,0 };

			return FrameWork::Memory::ReadMemory<Vector3D>(this + 0x90);
		}

		bool IsGodMode()
		{
			if (!this)
				return false;

			return FrameWork::Memory::ReadMemory<bool>(this + 0x189);
		}

		float GetHealth()
		{
			if (!this)
				return 0;

			return FrameWork::Memory::ReadMemory<float>(this + 0x280);
		}

		void SetHealth(float NewHealth)
		{
			if (!this)
				return;

			FrameWork::Memory::WriteMemory(this + 0x280, NewHealth);
		}

		uint64_t GetGRCViewPort()
		{
			if (!this)
				return 0;

			uint64_t NetObject = FrameWork::Memory::ReadMemory<uint64_t>(this + 0xD0);
		}

		uint32_t GetPedType()
		{
			if (!this)
				return 0;

			return FrameWork::Memory::ReadMemory<uint32_t>(this + Offsets::EntityType);
		}

		bool IsNPC()
		{
			uint32_t PedType = GetPedType();

			if (!PedType)
				return false;

			PedType = PedType << 11 >> 25;

			if (PedType != 2)
				return true;

			return false;
		}

		bool IsAnimal()
		{
			uint32_t PedType = GetPedType();

			if (!PedType)
				return false;

			PedType = PedType << 11 >> 25;

			if (PedType > 27)
				return true;

			return false;
		}
	};

	class CPedList
	{
	public:
		CPed* Ped(int Index)
		{
			if (!this)
				return 0;

			return (CPed*)FrameWork::Memory::ReadMemory<uint64_t>(this + (Index * 0x10));
		}
	};

	class CPedInterface
	{
	public:
		CPedList* PedList()
		{
			if (!this)
				return 0;

			return (CPedList*)FrameWork::Memory::ReadMemory<uint64_t>(this + 0x100);
		}

		uint64_t PedMaximum()
		{
			if (!this)
				return 0;

			return FrameWork::Memory::ReadMemory<uint64_t>(this + 0x108);
		}

		uint64_t PedsAtList()
		{
			if (!this)
				return 0;

			return FrameWork::Memory::ReadMemory<uint64_t>(this + 0x110);
		}
	};

	class CVehicle
	{
	public:
		Vector3D GetCoordinate()
		{
			if (!this)
				return Vector3D{ 0,0,0 };

			return FrameWork::Memory::ReadMemory<Vector3D>(this + 0x90);
		}
	};

	class CVehicleList
	{
	public:
		CVehicle* Vehicle(int Index)
		{
			if (!this)
				return 0;

			return (CVehicle*)FrameWork::Memory::ReadMemory<uint64_t>(this + (Index * 0x10));
		}
	};

	class CVehicleInterface
	{
	public:
		CVehicleList* VehicleList()
		{
			if (!this)
				return 0;

			return (CVehicleList*)FrameWork::Memory::ReadMemory<uint64_t>(this + 0x180);
		}

		uint64_t VehicleMaximum()
		{
			if (!this)
				return 0;

			return FrameWork::Memory::ReadMemory<uint64_t>(this + 0x188);
		}

		uint64_t VehiclesAtList()
		{
			if (!this)
				return 0;

			return FrameWork::Memory::ReadMemory<uint64_t>(this + 0x190);
		}
	};

	class CReplayInterface
	{
	public:
		CPedInterface* PedInterface()
		{
			if (!this)
				return 0;

			return (CPedInterface*)FrameWork::Memory::ReadMemory<uint64_t>(this + 0x18);
		}

		CVehicleInterface* ReplayInterface()
		{
			if (!this)
				return 0;

			return (CVehicleInterface*)FrameWork::Memory::ReadMemory<uint64_t>(this + 0x10);
		}
	};

	class CCamFollowPedCamera
	{
	public:
	};

	class CCamGameplayDirector
	{
	public:
		CCamFollowPedCamera* GetFollowPedCamera()
		{
			if (!this)
				return 0;

			return (CCamFollowPedCamera*)FrameWork::Memory::ReadMemory<uint64_t>(this + 0x3C0);
		}
	};

	class CWorld
	{
	public:
		CPed* LocalPlayer()
		{
			if (!this)
				return 0;

			return (CPed*)FrameWork::Memory::ReadMemory<uint64_t>(this + 0x8);
		}
	};
}