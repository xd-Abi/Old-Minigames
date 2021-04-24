#include "mgpch.h"
#include "Window.h"

namespace Minigames
{

	Window::Window()
	{
		m_Width = 1280;
		m_Height = 720;

		Init();
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void Window::Init()
	{
		if (!glfwInit())
			MG_ERROR("GLFW couldn't initialize!");
	
		glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

		m_Window = glfwCreateWindow(m_Width, m_Height, "Minigames", NULL, NULL);

		if (m_Window == NULL)
			MG_ERROR("Failed to create Window!");

		const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

		glfwSetWindowPos(m_Window, (vidmode->width - m_Width) / 2, (vidmode->height - m_Height) / 2);
		glfwMakeContextCurrent(m_Window);
		glfwShowWindow(m_Window);

	}

	void Window::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(m_Window);
	}
}