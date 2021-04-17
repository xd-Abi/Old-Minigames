#pragma once

#include "GLFW/glfw3.h"

namespace Minigames
{

	class Window
	{
	
	public:

		static void Create();
		static void Destroy();
		static void Update();
		static bool ShouldClose();
	
	private:

		static GLFWwindow* s_Window;
		static int s_Width;
		static int s_Height;
		
	};

}