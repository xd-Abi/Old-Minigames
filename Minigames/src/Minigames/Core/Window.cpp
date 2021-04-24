#include "mgpch.h"
#include "Window.h"

namespace Minigames
{

	Window::Window()
	{
		if (!glfwInit())
			MG_ERROR("GLFW couldn't initialize!");
		
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

		m_Window = glfwCreateWindow(1280, 720, "Minigames", NULL, NULL);
	
	}

	Window::~Window()
	{

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