#pragma once

#include "Window.h"

namespace Minigames
{

	class Application
	{

	public:

		Application();
		virtual ~Application();

		void Run();
		void Stop();

		Window& GetWindow() { return *m_Window; }

	public:

		static Application* Get() { return s_Instance; }

	private:

		bool m_Running = true;
		Scope<Window> m_Window;
	
	private:

		static Application* s_Instance;
	};

}