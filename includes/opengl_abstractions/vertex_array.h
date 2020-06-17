#ifndef OPENGLABSTRACTIONS_VERTEXARRAY_H_
#define OPENGLABSTRACTIONS_VERTEXARRAY_H_

#include <glad/glad.h>

namespace opengl
{
	class vertex_array
	{
	public:
		enum type
		{
			type_int = GL_INT,
			type_float = GL_FLOAT
		};
	public:
		vertex_array();
		~vertex_array();

		void bind() const;
		void un_bind() const;

		template<typename T>
		void add_attribute(int p_Components, type p_Type, int p_Stride)
		{
			glVertexAttribPointer(m_Count, p_Components, p_Type, GL_FALSE, p_Stride, (void*)m_Pointer);
			glEnableVertexAttribArray(m_Count);
			m_Pointer += (p_Components * sizeof(T));
			m_Count++;
		}

		const inline unsigned int get_id() const { return m_Id; };

	private:
		unsigned int m_Id;
		int m_Pointer = 0;
		int m_Count = 0;
	};
}

#endif // !OPENGLABSTRACTIONS_VERTEXARRAY_H_


