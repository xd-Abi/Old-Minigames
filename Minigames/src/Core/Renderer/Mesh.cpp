#include "mgpch.h"
#include "Mesh.h"
#include <glad/glad.h>

namespace Minigames
{

	Mesh::Mesh()
	{
		glCreateVertexArrays(1, &m_Vao);
		glCreateBuffers(1, &m_Vbo);
		glCreateBuffers(1, &m_Tbo);
		glCreateBuffers(1, &m_Ibo);

		m_DrawCount = 0;
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(1, &m_Vbo);
		glDeleteBuffers(1, &m_Tbo);
		glDeleteBuffers(1, &m_Ibo);
		glDeleteVertexArrays(1, &m_Vao);
	}

	void Mesh::Draw()
	{
		glBindVertexArray(m_Vao);
		glDrawElements(GL_TRIANGLES, m_DrawCount, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

	void Mesh::SetVertices(Vec<float> vertices, uint32_t dimension)
	{
		glBindVertexArray(m_Vao);


		glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, dimension, GL_FLOAT, GL_FALSE, 0, 0);
	}

	void Mesh::SetTexCoords(Vec<float> texCoords)
	{
		glBindVertexArray(m_Vao);

		glBindBuffer(GL_ARRAY_BUFFER, m_Tbo);
		glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	}


	void Mesh::SetIndices(Vec<uint32_t> indices)
	{

		m_DrawCount = indices.size() * sizeof(indices[0]);

		glBindVertexArray(m_Vao);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_DrawCount, &indices[0], GL_STATIC_DRAW);
	}
}