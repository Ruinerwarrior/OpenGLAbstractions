#include "../includes/opengl_abstractions/texture.h"

#include <stbimage/stb_image.h>

namespace opengl
{
	texture::texture() 
		: m_Height(0), m_Width(0)
	{
		glGenTextures(1, &m_Id);
	}

	texture::texture(const int p_Color, const int p_Width, const int p_Height) 
		: m_Width(p_Width), m_Height(p_Height)
	{
		glGenTextures(1, &m_Id);
		glBindTexture(GL_TEXTURE_2D, m_Id);
		glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, 1, 1);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &p_Color);
	}

	texture::texture(const char* p_ImagePath)
	{
		glGenTextures(1, &m_Id);
		glBindTexture(GL_TEXTURE_2D, m_Id);
		int nrChannels;
		unsigned char* data = stbi_load(p_ImagePath, &m_Width, &m_Height, &nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		stbi_image_free(data);
	}
	
	texture::texture(const target p_Target, const int p_Level, const interal_format p_InternalFormat, const int p_Width, int p_Height, const int p_Border, const format p_Format, const pixel_type p_Type, void* p_Data)
		: m_Width(p_Width), m_Height(p_Height)
	{
		glGenTextures(1, &m_Id);
		glBindTexture(p_Target, m_Id);
		glTexImage2D(p_Target, p_Level, p_InternalFormat, p_Width, p_Height, p_Border, p_Format, p_Type, p_Data);
	}

	texture::~texture()
	{
		glDeleteTextures(1, &m_Id);
	}

	void texture::bind() const
	{
		glBindTexture(GL_TEXTURE_2D, m_Id);
	}

	void texture::un_bind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void texture::bind_to_unit(const int p_Unit) const
	{
		glBindTextureUnit(p_Unit, m_Id);
	}

	void texture::bind_unit(unsigned int p_Id, unsigned short int p_Unit)
	{
		glBindTextureUnit(p_Unit, p_Id);
	}

	void texture::gen_mipmaps() const
	{
		glBindTexture(GL_TEXTURE_2D, m_Id);
	}
	
	void texture::set_parameter(tex_param p_Param, tex_param_value p_Value) const
	{
		glTexParameteri(GL_TEXTURE_2D, p_Param, p_Value);
	}
}