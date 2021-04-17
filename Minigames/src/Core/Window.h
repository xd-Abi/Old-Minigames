#pragma once

#include "GLFW/glfw3.h"

namespace Minigames
{

	class Window
	{
	
	public:

		static void Create();
		static void Show();
		static void Destroy();
		static void Update();
		static void SwapBuffers();
		static bool ShouldClose();
	
	private:

		static GLFWwindow* s_Window;
		static uint32_t s_Width;
		static uint32_t s_Height;
		
	};
}