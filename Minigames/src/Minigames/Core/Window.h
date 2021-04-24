#pragma once

#include <GLFW/glfw3.h>

namespace Minigames
{

	class Window
	{
	public:

		Window();
		virtual ~Window();

		void Update();
		bool ShouldClose();
		
		GLFWwindow* GetNativeWindow() { return m_Window; }

	private: 

		void Init();

	private:

		GLFWwindow* m_Window;
		int m_Width;
		int m_Height;
	};

}
