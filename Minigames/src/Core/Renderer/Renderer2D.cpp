#include "mgpch.h"
#include "Renderer2D.h"

namespace Minigames
{

	Ref<Mesh> Renderer2D::s_Quad;
	Ref<Shader> Renderer2D::s_Shader;

	void Renderer2D::Init()
	{
		s_Quad = CreateRef<Mesh>();
		s_Quad->SetVertices(Vec<float>
		{
			-0.5f, -0.5f,	// BOTTOM LEFT
			 0.5f, -0.5f,	// TOP LEFT
			 0.5f, 0.5f,	// TOP RIGHT
			-0.5f, 0.5f		// BOTTOM RIGHT
		}, 2);

		s_Quad->SetTexCoords(Vec<float>
		{
			0, 0,
			0, 1,
			1, 1,
			1, 0
		});

		s_Quad->SetIndices(Vec<uint32_t>
		{
			0, 1, 2,
			2, 3, 0
		});

		s_Shader = CreateRef<Shader>("QuadShader.glsl");
	}

	void Renderer2D::DrawQuad(const glm::vec2 pos, const glm::vec2 scale)
	{
		s_Shader->Bind();
		s_Quad->Draw();
		s_Shader->Unbind();
	}
}