#include "../includes/opengl_abstractions/texture.h"

#include <stbimage/stb_image.h>

namespace opengl
{
	texture::~texture()
	{
		glDeleteTextures(1, &m_id);
	}

	void texture::create() 
	{
		glGenTextures(1, &m_id);
	}

	void texture::create(const int p_color, const int p_width, const int p_height) 
	{
		m_width = p_width;
		m_height = p_height;
		glGenTextures(1, &m_id);
		glBindTexture(GL_TEXTURE_2D, m_id);
		glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, 1, 1);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &p_color);
	}

	void texture::create(const char* p_imagePath)
	{
		glGenTextures(1, &m_id);
		glBindTexture(GL_TEXTURE_2D, m_id);
		int nrChannels;
		unsigned char* data = stbi_load(p_imagePath, &m_width, &m_height, &nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		stbi_image_free(data);
	}
	
	void texture::create(const target p_target, const int p_level, const interal_format p_internalformat, const int p_width, int p_height, const int p_border, const format p_format, const pixel_type p_type, void* p_data)
	{
		m_width = p_width;
		m_height = p_height;
		glGenTextures(1, &m_id);
		glBindTexture(static_cast<GLenum>(p_target), m_id);
		glTexImage2D(static_cast<GLenum>(p_target), p_level, p_internalformat, p_width, p_height, p_border, p_format, p_type, p_data);
	}

	void texture::bind() const
	{
		glBindTexture(GL_TEXTURE_2D, m_id);
	}

	void texture::un_bind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void texture::bind_to_unit(const int p_Unit) const
	{
		glBindTextureUnit(p_Unit, m_id);
	}

	void texture::bind_unit(unsigned int p_Id, unsigned short int p_Unit)
	{
		glBindTextureUnit(p_Unit, p_Id);
	}

	void texture::gen_mipmaps() const
	{
		glBindTexture(GL_TEXTURE_2D, m_id);
	}
	
	void texture::set_parameter(tex_param p_param, tex_param_value p_value) const
	{
		glTexParameteri(GL_TEXTURE_2D, static_cast<GLenum>(p_param), p_value);
	}
}