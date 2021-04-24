#include "mgpch.h"
#include "ImGuiRenderer.h"

#include <imgui.h>
#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>

#include "Minigames/Core/Application.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>


namespace Minigames
{

	void ImGuiRenderer::Init()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui_ImplGlfw_InitForOpenGL(Application::Get()->GetWindow().GetNativeWindow(), true);
		ImGui_ImplOpenGL3_Init("#version 330");
	}

	void ImGuiRenderer::Shutdown()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiRenderer::BeginFrame()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiRenderer::EndFrame()
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}