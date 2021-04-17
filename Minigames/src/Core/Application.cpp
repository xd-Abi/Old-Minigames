#include "Application.h"
#include "Window.h"

namespace Minigames
{
	
	Application::Application()
	{
		m_Running = true;

		Window::Create();
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
	}
}