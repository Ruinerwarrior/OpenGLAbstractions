#ifndef OPENGLABSTRACTIONS_INDEXBUFFER_H_
#define OPENGLABSTRACTIONS_INDEXBUFFER_H_

#include <glad/glad.h>

namespace opengl
{
	class IndexBuffer
	{
	public:
		enum Usage
		{
			USAGE_STATIC_DRAW = GL_STATIC_DRAW,
			USAGE_DYNCAMIC_DRAW = GL_DYNAMIC_DRAW
		};

	public:
		IndexBuffer(const int size, Usage usage);
		IndexBuffer(const int size, const void* data, Usage usage);
		~IndexBuffer();

		void addData(const int size, const void* data, Usage usage) const;

		void bind() const;
		void unBind() const;

		const inline unsigned int getId() const { return id; };

	private:
		unsigned int id;
	};
}


#endif // !OPENGLABSTRACTIONS_INDEXBUFFER_H_
