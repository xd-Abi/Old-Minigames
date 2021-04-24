#include "mgpch.h"
#include "Log.h"
#include <stdlib.h>

namespace Minigames
{

	void Log::Init()
	{
		HideConsole();
		system("Color 02");
	}

	void Log::ShowConsole()
	{
	#ifdef MG_PLATFORM_WINDOWS
		::ShowWindow(::GetConsoleWindow(), SW_SHOW);
	#endif
	}

	void Log::HideConsole()
	{
	#ifdef MG_PLATFORM_WINDOWS
		::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	#endif
	}
}