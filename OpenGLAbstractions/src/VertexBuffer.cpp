#include "../includes/VertexBuffer.h"
#include <glad/glad.h>

namespace opengl
{
	VertexBuffer::VertexBuffer(const int size, Usage usage)
	{
		glGenBuffers(1, &id);
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, size, nullptr, usage);
	}

	VertexBuffer::VertexBuffer(const int size, const void* data, Usage usage)
	{
		glGenBuffers(1, &id);
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, usage);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &id);
	}

	void VertexBuffer::addData(const int size, const void* data, Usage usage) const
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, usage);
	}

	void VertexBuffer::addSubData(const int size, const void* data) const
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}

	void VertexBuffer::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}

	void VertexBuffer::unBind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
}