#ifndef OPENGLABSTRATCTIONS_VERTEXBUFFER_H_
#define OPENGLABSTRATCTIONS_VERTEXBUFFER_H_

#include <glad/glad.h>

namespace opengl
{
	class vertex_buffer
	{
	public:
		enum class usage : GLenum
		{
			usage_static_draw = GL_STATIC_DRAW,
			usage_dyncamic_draw = GL_DYNAMIC_DRAW
		};
	public:
		vertex_buffer() = default;
		~vertex_buffer();

		void create(const size_t p_size, const usage p_usage);
		void create(const size_t p_size, const void* p_data, const usage p_usage);
		

		void add_data(const size_t p_size, const void* p_data, const usage p_usage) const;
		void add_subdata(const size_t p_size, const void* p_data) const;

		void bind() const;
		void un_bind() const;

		const inline unsigned int getid() const { return m_id; };

	private:
		unsigned int m_id = 0;
	};
}

#endif // !OPENGLABSTRATCTIONS_VERTEXBUFFER_H_
