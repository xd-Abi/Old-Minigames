#pragma once

namespace Minigames
{

	class Mesh
	{
	
	public:

		Mesh();
		~Mesh();
		
		void Draw();
		void SetVertices(Vec<float> vertices, uint32_t demension);
		void SetTexCoords(Vec<float> texCoords);
		void SetIndices(Vec<uint32_t> indices);

	private:

		uint32_t m_Vao;
		uint32_t m_Vbo;
		uint32_t m_Tbo;
		uint32_t m_Ibo;
		uint32_t m_DrawCount;
	};

}
