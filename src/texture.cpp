#include "../includes/opengl_abstractions/Texture.h"

#include <stbimage/stb_image.h>

namespace opengl
{
	Texture::Texture() 
		: height(0), width(0)
	{
		glGenTextures(1, &id);
	}

	Texture::Texture(const int color, const int width, const int height) 
		: width(width), height(height)
	{
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, 1, 1);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &color);
	}

	Texture::Texture(const char* imagePath)
	{
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		int nrChannels;
		unsigned char* data = stbi_load(imagePath, &width, &height, &nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		stbi_image_free(data);
	}
	
	Texture::Texture(const Target target, const int level, const InteralFormat internalFormat, const int width, int height, const int border, const Format format, const PixelType type, void* data)
		: width(width), height(height)
	{
		glGenTextures(1, &id);
		glBindTexture(target, id);
		glTexImage2D(target, level, internalFormat, width, height, border, format, type, data);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &id);
	}

	void Texture::bind() const
	{
		glBindTexture(GL_TEXTURE_2D, id);
	}

	void Texture::unBind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::bindToUnit(const int unit) const
	{
		glBindTextureUnit(unit, id);
	}

	void Texture::bindUnit(unsigned int id, unsigned short int unit)
	{
		glBindTextureUnit(unit, id);
	}

	void Texture::genMipMaps() const
	{
		glBindTexture(GL_TEXTURE_2D, id);
	}
	
	void Texture::setParameter(TexParam param, TexParamValue value) const
	{
		glTexParameteri(GL_TEXTURE_2D, param, value);
	}
}