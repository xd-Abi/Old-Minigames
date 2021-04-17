#include "mgpch.h"
#include "Window.h"
#include "Renderer/Texture.h"
#include "Renderer/Renderer2D.h"

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
		glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
		glfwWindowHint(GLFW_SAMPLES, 4);

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

	/* Drawing Custom Title bar */
	

	Ref<Texture> WindowTitleBar::s_TitleTex;

	void WindowTitleBar::Init()
	{
		s_TitleTex = CreateRef<Texture>("assets/icon/title.png");
	}

	void WindowTitleBar::Draw()
	{
		Renderer2D::DrawTexture(glm::vec3(10, 695, 0), glm::vec2(108, 24), s_TitleTex);
		Renderer2D::DrawQuad(glm::vec3(0, 10, 0), glm::vec2(1280, 10), glm::vec4(0.1f, 0.1f, 0.1f, 1));
		Renderer2D::DrawQuad(glm::vec3(0, 70, 0), glm::vec2(1280, 10), glm::vec4(1, 0.1f, 0.1f, 1));
	}
}