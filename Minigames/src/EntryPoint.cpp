
#include "Core/Application.h"

int main(int argc, char* argv[])
{
	Minigames::Application* app = new Minigames::Application();
	app->Run();
	delete app;
}