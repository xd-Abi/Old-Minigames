#include "Window.h"

namespace Minigames
{

	GLFWwindow* Window::s_Window;
	int Window::s_Width;
	int Window::s_Height;
	
	void Window::Create()
	{
		if (!glfwInit())
		{
			/* Error handling */
		}

		s_Width = 1280;
		s_Height = 720;
		s_Window = glfwCreateWindow(s_Width, s_Height, "Minigames", NULL, NULL);
		
		if (s_Window == NULL)
		{
			/* Error handling */
		}

		const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(s_Window, (vidmode->width - s_Width) / 2, (vidmode->height - s_Height) / 2);
		
		glfwMakeContextCurrent(s_Window);
	}

	void Window::Destroy()
	{
		glfwDestroyWindow(s_Window);
		glfwTerminate();
	}

	void Window::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(s_Window);
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(s_Window);
	}
}