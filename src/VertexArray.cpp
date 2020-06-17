#include "../includes/opengl_abstractions/VertexArray.h"

namespace opengl
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &id);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &id);
	}

	void VertexArray::bind() const
	{
		glBindVertexArray(id);
	}

	void VertexArray::unBind() const
	{
		glBindVertexArray(0);
	}
}