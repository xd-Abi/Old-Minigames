#pragma once

namespace Minigames
{

	class Renderer
	{
		
	public:

		static void Init();
		static void Render();
		static void Shutdown();

	private:

		static void Begin();
		static void End();
	};

}
