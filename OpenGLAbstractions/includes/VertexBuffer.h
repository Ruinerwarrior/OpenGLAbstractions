#ifndef OPENGLABSTRATCTIONS_VERTEXBUFFER_H_
#define OPENGLABSTRATCTIONS_VERTEXBUFFER_H_

#include <glad/glad.h>

namespace opengl
{
	class VertexBuffer
	{
		enum Usage
		{
			USAGE_STATIC_DRAW = GL_STATIC_DRAW,
			USAGE_DYNCAMIC_DRAW = GL_DYNAMIC_DRAW
		};
	public:
		VertexBuffer(const int size, Usage usage);
		VertexBuffer(const int size, const void* data, Usage usage);
		~VertexBuffer();

		void addData(const int size, const void* data, Usage usage) const;
		void addSubData(const int size, const void* data) const;

		void bind() const;
		void unBind() const;

		const inline unsigned int getId() const { return id; };

	private:
		unsigned int id;
	};
}

#endif // !OPENGLABSTRATCTIONS_VERTEXBUFFER_H_
