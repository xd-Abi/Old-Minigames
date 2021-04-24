#pragma once

namespace Minigames
{

	class Log
	{
	
	public:

		static void Init();
		
		template<typename  T>
		static void Error(const T& msg)
		{
			ShowConsole();
		
			std::cout << "\x1B[37m[Minigames] \x1B[31m" << msg << "\033[0m\t\t" << std::endl;
			std::exit(-1);
		}

		template<typename  T>
		static void DebugLog(const T& msg)
		{
			ShowConsole();

			std::cout << msg << std::endl;
		}

	private:

		static void ShowConsole();
		static void HideConsole();
	};

}

#define MG_ERROR(...) ::Minigames::Log::Error(__VA_ARGS__)
#define MG_DEBUG_LOG(...) ::Minigames::Log::DebugLog(__VA_ARGS__)