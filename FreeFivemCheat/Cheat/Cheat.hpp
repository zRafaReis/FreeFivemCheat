#pragma once

// ImGui
#include <FrameWork/Dependencies/ImGui/imgui.h>
#include <FrameWork/Dependencies/ImGui/imgui_impl_dx11.h>
#include <FrameWork/Dependencies/ImGui/imgui_impl_win32.h>
#include <FrameWork/Dependencies/ImGui/imgui_internal.h>

#include "Options.hpp"

namespace Cheat
{
	void Initialize();
	void ShutDown();
}