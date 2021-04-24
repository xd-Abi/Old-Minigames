#include "mgpch.h"
#include "Renderer.h"
#include "Renderer2D.h"
#include "RenderAPI.h"

#include "Minigames/ImGui/ImGuiRenderer.h"
#include <imgui.h>

#include "Texture.h"

namespace Minigames
{

	static Ref<Texture> test_image;
	static Ref<Texture> test_image2;


	void Renderer::Init()
	{
		RenderAPI::Init();
		RenderAPI::SetClearColor(0.07f, 0.07f, 0.07f, 1);

		Renderer2D::Init();
		ImGuiRenderer::Init();

		test_image = CreateRef<Texture>("assets/test.png", false);
		test_image2 = CreateRef<Texture>("assets/test.jpg", true);
	}
	
	void Renderer::Shutdown()
	{
		ImGuiRenderer::Shutdown();
	}

	void Renderer::Begin()
	{
		RenderAPI::Clear();
		ImGuiRenderer::BeginFrame();
	}

	void Renderer::Render()
	{
		Begin();


		Renderer2D::DrawQuad(glm::vec3(0, 0, 0), glm::vec2(120, 40), glm::vec4(1, 0, 0, 1));
		Renderer2D::DrawQuad(glm::vec3(0, 710, 0), glm::vec2(1280, 10), glm::vec4(1, 0, 0, 1));
		Renderer2D::DrawTexture(glm::vec3(420, 200, 0), glm::vec2(100, 100), test_image);
		Renderer2D::DrawTexture(glm::vec3(800, 200, 0), glm::vec2(300, 300), test_image2);


		ImGui::Begin("TEST");
		ImGui::Text("TESTTST");
		ImGui::Image((ImTextureID)test_image2->GetId(), ImVec2(test_image2->GetWidth(), test_image2->GetHeight()));
		ImGui::End();

		End();
	}

	void Renderer::End()
	{
		ImGuiRenderer::EndFrame();
	}
}