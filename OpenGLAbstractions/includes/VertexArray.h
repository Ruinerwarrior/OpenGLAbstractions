#ifndef OPENGLABSTRACTIONS_VERTEXARRAY_H_
#define OPENGLABSTRACTIONS_VERTEXARRAY_H_

#include "../extern/glad/glad/glad.h"

namespace opengl
{
	class VertexArray
	{
	public:
		enum Type
		{
			TYPE_INT = GL_INT,
			TYPE_FLOAT = GL_FLOAT
		};
	public:
		VertexArray();
		~VertexArray();

		void bind() const;
		void unBind() const;

		template<typename T>
		void addAttribute(int components, Type type, int stride)
		{
			glVertexAttribPointer(count, components, type, GL_FALSE, stride, (void*)pointer);
			glEnableVertexAttribArray(count);
			pointer += (components * sizeof(T));
			count++;
		}

		const inline unsigned int getId() const { return id; };

	private:
		unsigned int id;
		int pointer = 0;
		int count = 0;
	};
}

#endif // !OPENGLABSTRACTIONS_VERTEXARRAY_H_


