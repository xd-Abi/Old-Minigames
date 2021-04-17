#include "mgpch.h"
#include "Core/Application.h"

int main(int argc, char* argv[])
{
	Minigames::Log::Init();

	Minigames::Application* app = new Minigames::Application();
	app->Run();
	delete app;
}