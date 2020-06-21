#include "../includes/opengl_abstractions/index_buffer.h"

namespace opengl
{
	index_buffer::~index_buffer()
	{
		glDeleteBuffers(1, &m_id);
	}

	void index_buffer::create(const size_t p_size, usage p_usage)
	{
		glGenBuffers(1, &m_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_size, nullptr, static_cast<GLenum>(p_usage));
	}

	void index_buffer::create(const size_t p_size, const void* p_data, usage p_usage)
	{
		glGenBuffers(1, &m_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_size, p_data, static_cast<GLenum>(p_usage));
	}

	void index_buffer::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
	}

	void index_buffer::un_bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void index_buffer::add_data(const size_t p_size, const void* p_data, usage p_usage) const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(p_data), p_data, static_cast<GLenum>(p_usage));
	}
}