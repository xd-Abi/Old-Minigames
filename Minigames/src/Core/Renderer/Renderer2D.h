#pragma once

#include "glm/glm.hpp"
#include "Mesh.h"
#include "Shader.h"

namespace Minigames
{

	class Renderer2D
	{
		
	public:

		static void Init();
		static void DrawQuad(const glm::vec2 pos, const glm::vec2 scale);

	private:

		static Ref<Mesh> s_Quad;
		static Ref<Shader> s_Shader;
	};

}