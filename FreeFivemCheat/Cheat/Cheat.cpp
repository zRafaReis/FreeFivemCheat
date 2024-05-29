#include "Cheat.hpp"

#include "FivemSDK/Fivem.hpp"

#include <thread>
#include <FrameWork/FrameWork.hpp>

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


	}

	void ShutDown()
	{

	}
}