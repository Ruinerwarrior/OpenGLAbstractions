#ifndef OPENGLABSTRACTIONS_INDEXBUFFER_H_
#define OPENGLABSTRACTIONS_INDEXBUFFER_H_

#include <glad/glad.h>

namespace opengl
{
	class index_buffer
	{
	public:
		enum usage
		{
			usage_static_draw = GL_STATIC_DRAW,
			usage_dyncamic_draw = GL_DYNAMIC_DRAW
		};

	public:
		index_buffer(const int p_Size, usage p_Usage);
		index_buffer(const int p_Size, const void* data, usage p_Usage);
		~index_buffer();

		void add_data(const int p_Size, const void* p_Data, usage p_Usage) const;

		void bind() const;
		void un_bind() const;

		const inline unsigned int get_id() const { return m_Id; };

	private:
		unsigned int m_Id;
	};
}


#endif // !OPENGLABSTRACTIONS_INDEXBUFFER_H_
