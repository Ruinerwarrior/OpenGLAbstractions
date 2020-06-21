#include "../includes/opengl_abstractions/vertex_buffer.h"

namespace opengl
{
	vertex_buffer::~vertex_buffer()
	{
		glDeleteBuffers(1, &m_id);
	}

	void vertex_buffer::create(const size_t p_size, const usage p_usage)
	{
		glGenBuffers(1, &m_id);
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
		glBufferData(GL_ARRAY_BUFFER, p_size, nullptr, static_cast<GLenum>(p_usage));
	}

	void vertex_buffer::create(const size_t p_size, const void* p_data, const usage p_usage)
	{
		glGenBuffers(1, &m_id);
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(p_data), p_data, static_cast<GLenum>(p_usage));
	}

	void vertex_buffer::add_data(const size_t p_size, const void* p_data, const usage p_usage) const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(p_data), p_data, static_cast<GLenum>(p_usage));
	}

	void vertex_buffer::add_subdata(const size_t p_size, const void* p_data) const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
		glBufferSubData(GL_ARRAY_BUFFER, 0, p_size, p_data);
	}

	void vertex_buffer::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
	}

	void vertex_buffer::un_bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
}