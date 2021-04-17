#pragma once

namespace Minigames
{ 

	class RenderMaster
	{
		
	public:

		static void Init();
		static void Render();
	};

	class RenderAPI
	{
	
	public:

		static void Init();
		static void Clear();
		static void SetClearColor(float r, float g, float b, float a);
		static void SetViewPort(int x, int y, int width, int height);
	};
}
