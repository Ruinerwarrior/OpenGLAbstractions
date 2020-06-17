#ifndef OPENGLABSTRATCTIONS_VERTEXBUFFER_H_
#define OPENGLABSTRATCTIONS_VERTEXBUFFER_H_

#include <glad/glad.h>

namespace opengl
{
	class vertex_buffer
	{
	public:
		enum usage
		{
			usage_static_draw = GL_STATIC_DRAW,
			usage_dyncamic_draw = GL_DYNAMIC_DRAW
		};
	public:
		vertex_buffer(const int p_Size, usage p_Usage);
		vertex_buffer(const int p_Size, const void* p_Data, usage p_Usage);
		~vertex_buffer();

		void add_data(const int p_Size, const void* p_Data, usage p_Usage) const;
		void add_subdata(const int p_Size, const void* p_Data) const;

		void bind() const;
		void un_bind() const;

		const inline unsigned int getId() const { return m_Id; };

	private:
		unsigned int m_Id;
	};
}

#endif // !OPENGLABSTRATCTIONS_VERTEXBUFFER_H_
