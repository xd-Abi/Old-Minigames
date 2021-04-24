#pragma once

namespace Minigames
{

	class ImGuiRenderer
	{

	public:
	
		static void Init();
		static void Shutdown();
		static void BeginFrame();
		static void EndFrame();
	};

}
