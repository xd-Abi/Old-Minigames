#include "mgpch.h"
#include "RenderAPI.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Minigames
{
	void RenderAPI::Init()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			MG_ERROR("Glad couldn't initialize!");

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_DEPTH_TEST);
	}

	void RenderAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void RenderAPI::SetClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

}