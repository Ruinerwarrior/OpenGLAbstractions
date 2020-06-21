#include "../includes/opengl_abstractions/vertex_array.h"

namespace opengl
{
	vertex_array::~vertex_array()
	{
		glDeleteVertexArrays(1,  &m_id);
	}

	void vertex_array::create()
	{
		glGenVertexArrays(1, &m_id);
	}

	void vertex_array::bind() const
	{
		glBindVertexArray(m_id);
	}

	void vertex_array::un_bind() const
	{
		glBindVertexArray(0);
	}
}