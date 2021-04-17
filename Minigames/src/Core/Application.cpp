#include "mgpch.h"
#include "Application.h"
#include "Window.h"
#include "Renderer/RenderAPI.h"

namespace Minigames
{
	
	Application::Application()
	{
		m_Running = true;

		Window::Create();
		RenderMaster::Init();

		/* Initialize Game */

		Window::Show();
	}

	Application::~Application()
	{
		Window::Destroy();
	}

	void Application::Run()
	{

		while (m_Running)
		{
			Update();
		}
	}

	void Application::Update()
	{
		if (Window::ShouldClose())
			m_Running = false;
		
		Window::Update();
		RenderMaster::Render();
	}
}