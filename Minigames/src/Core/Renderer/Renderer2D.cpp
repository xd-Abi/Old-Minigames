#include "mgpch.h"
#include "Renderer2D.h"
#include "glm/gtc/matrix_transform.hpp"

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
			 0.5f, -0.5f,	// BOTTOM RIGHT
			 0.5f,  0.5f,	// TOP RIGHT
			-0.5f,  0.5f	// TOP LEFT
		}, 2);

		s_Quad->SetTexCoords(Vec<float>
		{
			0, 0,
			1, 0,
			1, 1,
			0, 1
		});

		s_Quad->SetIndices(Vec<uint32_t>
		{
			0,3,2,
			2,1,0
		});

		s_Shader = CreateRef<Shader>("QuadShader.glsl");
	}

	void Renderer2D::DrawQuad(const glm::vec3 pos, const glm::vec2 scale)
	{
		s_Shader->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::scale(glm::mat4(1.0f), { scale.x, scale.y, 1.0f });

		s_Shader->SetMat4("mvp", transform);
		s_Shader->SetFloat("use_color", 0);
		s_Quad->Draw();
		s_Shader->Unbind();
	}

	void Renderer2D::DrawQuad(const glm::vec3 pos, const glm::vec2 scale, const glm::vec4 color)
	{
		s_Shader->Bind();

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::scale(glm::mat4(1.0f), { scale.x, scale.y, 1.0f });

		s_Shader->SetMat4("mvp", transform);
		s_Shader->SetFloat("use_color", 1);
		s_Shader->SetFloat4("color", color);
		s_Quad->Draw();
		s_Shader->Unbind();
	}

	void Renderer2D::DrawTexture(const glm::vec3 pos, const glm::vec2 scale, const Ref<Texture> texture)
	{
		texture->Bind(0);
		s_Shader->Bind();
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::scale(glm::mat4(1.0f), { scale.x, scale.y, 1.0f });
		s_Shader->SetMat4("mvp", transform);
		s_Shader->SetFloat("use_color", 0);
		s_Shader->SetFloat("use_texture", 1);
		s_Shader->SetFloat("sampler", 0);
		s_Quad->Draw();
		s_Shader->Unbind();
	}
}