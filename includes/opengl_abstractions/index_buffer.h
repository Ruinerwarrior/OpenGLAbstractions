#ifndef OPENGLABSTRACTIONS_INDEXBUFFER_H_
#define OPENGLABSTRACTIONS_INDEXBUFFER_H_

#include <glad/glad.h>

namespace opengl
{
	class index_buffer
	{
	public:
		enum class usage : GLenum
		{
			usage_static_draw = GL_STATIC_DRAW,
			usage_dyncamic_draw = GL_DYNAMIC_DRAW
		};

	public:
		index_buffer() = default;
		~index_buffer();

		void create(const size_t p_size, usage p_usage);
		void create(const size_t p_size, const void* data, usage p_usage);

		void add_data(const size_t p_size, const void* p_data, usage p_usage) const;

		void bind() const;
		void un_bind() const;

		const inline unsigned int get_id() const { return m_id; };

	private:
		unsigned int m_id;
	};
}


#endif // !OPENGLABSTRACTIONS_INDEXBUFFER_H_
