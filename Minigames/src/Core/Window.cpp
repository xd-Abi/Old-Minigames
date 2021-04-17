#include "Window.h"

namespace Minigames
{

	GLFWwindow* Window::s_Window;
	uint32_t Window::s_Width;
	uint32_t Window::s_Height;
	
	void Window::Create()
	{
		if (!glfwInit())
		{
			/* Error handling */
		}

		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

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

	void Window::Show()
	{
		glfwShowWindow(s_Window);
	}

	void Window::Destroy()
	{
		glfwDestroyWindow(s_Window);
		glfwTerminate();
	}

	void Window::Update()
	{
		glfwPollEvents();
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(s_Window);
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(s_Window);
	}
}