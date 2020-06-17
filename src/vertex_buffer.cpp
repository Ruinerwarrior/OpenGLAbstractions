#include "../includes/opengl_abstractions/vertex_buffer.h"

namespace opengl
{
	vertex_buffer::vertex_buffer(const int p_Size, usage p_Usage)
	{
		glGenBuffers(1, &m_Id);
		glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		glBufferData(GL_ARRAY_BUFFER, p_Size, nullptr, p_Usage);
	}

	vertex_buffer::vertex_buffer(const int p_Size, const void* p_Data, usage p_Usage)
	{
		glGenBuffers(1, &m_Id);
		glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(p_Data), p_Data, p_Usage);
	}

	vertex_buffer::~vertex_buffer()
	{
		glDeleteBuffers(1, &m_Id);
	}

	void vertex_buffer::add_data(const int p_Size, const void* p_Data, usage p_Usage) const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(p_Data), p_Data, p_Usage);
	}

	void vertex_buffer::add_subdata(const int p_Size, const void* p_Data) const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		glBufferSubData(GL_ARRAY_BUFFER, 0, p_Size, p_Data);
	}

	void vertex_buffer::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_Id);
	}

	void vertex_buffer::un_bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
}