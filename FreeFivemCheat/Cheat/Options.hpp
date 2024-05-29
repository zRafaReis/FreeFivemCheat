#pragma once

#include <Windows.h>

namespace Cheat
{
	class Options
	{
	public:
		struct General
		{
			bool ShutDown = false;
			int MenuKey = VK_INSERT;
			int ThreadDelay = 0;
		}General;
	};
}

inline Cheat::Options g_Options;