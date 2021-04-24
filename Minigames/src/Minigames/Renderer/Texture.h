#pragma once

namespace Minigames
{

	class Texture
	{
		
	public:

		Texture(const std::string& path, bool imguiUsage);
		~Texture();

		void Bind(uint32_t slot = 0);
		uint32_t GetWidth() { return m_Width; }
		uint32_t GetHeight() { return m_Height; }
		uint32_t GetId() { return m_ID; }

	private:

		uint32_t m_Width, m_Height;
		uint32_t m_ID;
	};

}