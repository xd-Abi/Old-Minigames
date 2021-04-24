#include "mgpch.h"
#include "Application.h"

#include "Minigames/Renderer/Renderer.h"

namespace Minigames
{

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		if (s_Instance != nullptr)
			return;

		s_Instance = this;
		m_Window = CreateScope<Window>();
		
		Renderer::Init();
	}

	Application::~Application()
	{
		Renderer::Shutdown();
	}

	void Application::Run()
	{
		while (m_Running)
		{ 

			if (m_Window->ShouldClose())
				Stop();

			Renderer::Render();
			m_Window->Update();
		}
	}

	void Application::Stop()
	{
		m_Running = false;
	}
}