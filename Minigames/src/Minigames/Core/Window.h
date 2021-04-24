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
		
	private:

		GLFWwindow* m_Window;
	};

}
