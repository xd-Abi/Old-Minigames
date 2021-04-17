#pragma once

#include "GLFW/glfw3.h"
#include "Renderer/Texture.h"

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

	class WindowTitleBar
	{

	public:

		static void Init();
		static void Draw();

	private:

		static Ref<Texture> s_TitleTex;
	};
}