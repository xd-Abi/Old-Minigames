#pragma once

#include "glm/glm.hpp"

namespace Minigames
{

	class Shader
	{
	
	public:

		Shader(const std::string& filepath);
		Shader(const std::string& vertexShader, const std::string& fragmentShader);
		~Shader();

		void Bind();
		void Unbind();

		void SetInt(const std::string& name, int value);
		void SetIntArray(const std::string& name, int* values, uint32_t count);
		void SetFloat(const std::string& name, float value);
		void SetFloat2(const std::string& name, const glm::vec2& value);
		void SetFloat3(const std::string& name, const glm::vec3& value);
		void SetFloat4(const std::string& name, const glm::vec4& value);
		void SetMat4(const std::string& name, const glm::mat4& value);

	private:

		/* Reading Shaders from file */
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum, std::string> Shader::PreProcess(const std::string& source);

		void Compile(const std::unordered_map<GLenum, std::string>& shaderSource);

	private:

		uint32_t m_ID;
		GLint m_Shaders[];
	};

}
