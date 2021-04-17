#include "RenderAPI.h"
#include "Window.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Minigames
{
	/* RenderMaster */

	void RenderMaster::Init()
	{
		RenderAPI::Init();
		RenderAPI::SetClearColor(0.05f, 0.05f, 0.05f, 1);

	}

	void RenderMaster::Render()
	{

		RenderAPI::Clear();

		Window::SwapBuffers();
	}

	/* RenderAPI */

	void RenderAPI::Init()
	{
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		if (status == NULL)
		{
			/* Error handling */
		}
		
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
		glClearColor(r,g,b,a);
	}

	void RenderAPI::SetViewPort(int x, int y, int width, int height)
	{
		SetViewPort(x, y, width, height);
	}
}