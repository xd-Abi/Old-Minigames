#pragma once

#include "glm/glm.hpp"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

namespace Minigames
{

	class Renderer2D
	{
		
	public:

		static void Init();
		static void DrawQuad(const glm::vec3 pos, const glm::vec2 scale);
		static void DrawQuad(const glm::vec3 pos, const glm::vec2 scale, const glm::vec4 color);
		static void DrawTexture(const glm::vec3 pos, const glm::vec2 scale, const Ref<Texture> texture);

	private:

		static Ref<Mesh> s_Quad;
		static Ref<Shader> s_Shader;
	};

}