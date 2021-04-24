#pragma once

namespace Minigames
{

	class Application
	{

	public:

		Application();
		virtual ~Application();

		void Run();
		void Stop();

	private:

		bool m_IsRunning;
	};

}