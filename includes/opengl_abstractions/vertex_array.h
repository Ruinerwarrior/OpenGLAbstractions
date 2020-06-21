#ifndef OPENGLABSTRACTIONS_VERTEXARRAY_H_
#define OPENGLABSTRACTIONS_VERTEXARRAY_H_

#include <glad/glad.h>

namespace opengl
{
	class vertex_array
	{
	public:
		enum class type : GLenum
		{
			type_int = GL_INT,
			type_float = GL_FLOAT
		};
	public:
		vertex_array() = default;
		~vertex_array();

		void create();

		void bind() const;
		void un_bind() const;

		template<typename t>
		void add_attribute(const int p_components, const type p_type, const int p_stride)
		{
			glVertexAttribPointer(m_count, p_components, static_cast<GLenum>(p_type), GL_FALSE, p_stride, (void*)m_pointer);
			glEnableVertexAttribArray(m_count);
			m_pointer += (p_components * sizeof(t));
			m_count++;
		}

		const inline unsigned int get_id() const { return m_id; };

	private:
		unsigned int m_id = 0;
		int m_pointer = 0;
		int m_count = 0;
	};
}

#endif // !OPENGLABSTRACTIONS_VERTEXARRAY_H_


