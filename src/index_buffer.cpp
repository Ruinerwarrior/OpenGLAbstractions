#include "../includes/opengl_abstractions/index_buffer.h"

namespace opengl
{
	index_buffer::index_buffer(const int p_Size, usage p_Usage)
	{
		glGenBuffers(1, &m_Id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_Size, nullptr, p_Usage);
	}

	index_buffer::index_buffer(const int p_Size, const void* p_Data, usage p_Usage)
	{
		glGenBuffers(1, &m_Id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_Size, p_Data, p_Usage);
	}

	void index_buffer::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
	}

	void index_buffer::un_bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void index_buffer::add_data(const int p_Size, const void* p_Data, usage p_Usage) const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(p_Data), p_Data, p_Usage);
	}

	index_buffer::~index_buffer()
	{
		glDeleteBuffers(1, &m_Id);
	}
}