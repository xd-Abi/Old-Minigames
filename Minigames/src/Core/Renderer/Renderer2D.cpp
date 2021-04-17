#include "mgpch.h"
#include "Renderer2D.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/matrix_operation.hpp"

namespace Minigames
{

	Ref<Mesh> Renderer2D::s_Quad;
	Ref<Shader> Renderer2D::s_QuadShader;
	Ref<Shader> Renderer2D::s_TextureShader;

	static glm::mat4 s_OrthoGraphicsMatrix;

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

		s_QuadShader = CreateRef<Shader>("QuadShader.glsl");
		s_TextureShader = CreateRef<Shader>("TextureShader.glsl");

		s_OrthoGraphicsMatrix = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f);
	}

	void Renderer2D::DrawQuad(const glm::vec3 pos, const glm::vec2 scale, const glm::vec4 color)
	{
		s_QuadShader->Bind();

		glm::vec3 position = glm::vec3(pos.x + scale.x / 2, pos.y + scale.y / 2, pos.z);
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), { scale.x, scale.y, 1.0f });

		s_QuadShader->SetMat4("mvp", transform);
		s_QuadShader->SetMat4("ortho", s_OrthoGraphicsMatrix);
		s_QuadShader->SetFloat4("color", color);
		s_Quad->Draw();
		s_QuadShader->Unbind();
	}

	void Renderer2D::DrawTexture(const glm::vec3 pos, const glm::vec2 scale, const Ref<Texture> texture)
	{
		texture->Bind(0);
		s_TextureShader->Bind();

		glm::vec3 position = glm::vec3(pos.x + scale.x / 2, pos.y + scale.y / 2, pos.z);
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), { scale.x, scale.y, 1.0f });

		s_TextureShader->SetMat4("mvp", transform);
		s_TextureShader->SetMat4("ortho", s_OrthoGraphicsMatrix);
		s_TextureShader->SetFloat("sampler", 0);
		s_Quad->Draw();
		s_TextureShader->Unbind();
	}
}