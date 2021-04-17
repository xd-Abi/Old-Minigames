#pragma once

namespace Minigames
{

	class Application
	{

	public:

		Application();
		~Application();

		void Run();

	private:

		void Update();

	private:

		bool m_Running;
	};

}