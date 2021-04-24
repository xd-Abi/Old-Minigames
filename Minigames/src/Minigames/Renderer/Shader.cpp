#include "mgpch.h"
#include "Shader.h"

#include <fstream>

#include "Minigames/Utils/Util.h"
#include "glm/gtc/type_ptr.hpp"

namespace Minigames
{

	static GLenum ShaderTypeFromString(const std::string& type)
	{
		if (type == "vertex")
			return GL_VERTEX_SHADER;
		if (type == "fragment" || type == "pixel")
			return GL_FRAGMENT_SHADER;

		return 0;
	}

	Shader::Shader(const std::string& filepath)
	{

		m_ID = glCreateProgram();
		std::string source = ReadFile("assets/shaders/" + filepath);
		auto shaderSources = PreProcess(source);
		Compile(shaderSources);
	}

	Shader::Shader(const std::string& vertexShader, const std::string& fragmentShader)
	{
		m_ID = glCreateProgram();

		std::unordered_map<GLenum, std::string> shaderSources;
		shaderSources[GL_VERTEX_SHADER] = vertexShader;
		shaderSources[GL_FRAGMENT_SHADER] = fragmentShader;

		Compile(shaderSources);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_ID);
	}

	std::string Shader::ReadFile(const std::string& filepath)
	{

		std::string result;
		std::ifstream in(filepath, std::ios::in | std::ios::binary); // ifstream closes itself due to RAII
		if (in)
		{
			in.seekg(0, std::ios::end);
			size_t size = in.tellg();
			if (size != -1)
			{
				result.resize(size);
				in.seekg(0, std::ios::beg);
				in.read(&result[0], size);
			}
			else
			{
				MG_ERROR("Could not read from file " + filepath);
			}
		}
		else
		{
			MG_ERROR("Could not open file " + filepath);
		}

		return result;
	
	}

	std::unordered_map<GLenum, std::string> Shader::PreProcess(const std::string& source)
	{
		std::unordered_map<GLenum, std::string> shaderSources;

		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t pos = source.find(typeToken, 0); //Start of shader type declaration line
		while (pos != std::string::npos)
		{
			size_t eol = source.find_first_of("\r\n", pos); //End of shader type declaration line
			
			size_t begin = pos + typeTokenLength + 1; //Start of shader type name (after "#type " keyword)
			std::string type = source.substr(begin, eol - begin);
			size_t nextLinePos = source.find_first_not_of("\r\n", eol); //Start of shader code after shader type declaration line

			pos = source.find(typeToken, nextLinePos); //Start of next shader type declaration line

			shaderSources[ShaderTypeFromString(type)] = (pos == std::string::npos) ? source.substr(nextLinePos) : source.substr(nextLinePos, pos - nextLinePos);
		}

		return shaderSources;
	}

	void Shader::Compile(const std::unordered_map<GLenum, std::string>& shaderSource)
	{

		std::array<GLenum, 2> glShaderIDs;

		int glShaderIndex = 0;

		for (auto& kv : shaderSource)
		{
			GLenum type = kv.first;
			const std::string& source = kv.second;

			GLuint shader = glCreateShader(type);
			const GLchar* sourceCStr = source.c_str();
			glShaderSource(shader, 1, &sourceCStr, 0);
			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(shader);

				MG_ERROR(infoLog.data());
				MG_ERROR("Shader compilation failed!");
			}

			glAttachShader(m_ID, shader);
		}


		glLinkProgram(m_ID);

		GLint isLinked = 0;
		glGetProgramiv(m_ID, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_ID, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(m_ID, maxLength, &maxLength, &infoLog[0]);
			glDeleteProgram(m_ID);

			for (auto id : glShaderIDs)
				glDeleteShader(id);

			MG_ERROR(infoLog.data());
			MG_ERROR("Shader link failure!");
			return;
		}

		for (auto shaderID : glShaderIDs)
		{
			glDetachShader(m_ID, shaderID);
			glDeleteShader(shaderID);
		}
	}

	void Shader::Bind()
	{
		glUseProgram(m_ID);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	void Shader::SetInt(const std::string& name, int value)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform1i(location, value);
	}

	void Shader::SetIntArray(const std::string& name, int* values, uint32_t count)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform1iv(location, count, values);
	}

	void Shader::SetFloat(const std::string& name, float value)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform1f(location, value);
	}

	void Shader::SetFloat2(const std::string& name, const glm::vec2& value)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform2f(location, value.x, value.y);
	}

	void Shader::SetFloat3(const std::string& name, const glm::vec3& value)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform3f(location, value.x, value.y, value.z);
	}

	void Shader::SetFloat4(const std::string& name, const glm::vec4& value)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}

	void Shader::SetMat4(const std::string& name, const glm::mat4& matrix)
	{
		GLint location = glGetUniformLocation(m_ID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}
}