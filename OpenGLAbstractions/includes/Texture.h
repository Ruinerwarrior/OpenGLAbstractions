#ifndef OPENGLABSTRACTIONS_TEXTURE_H_
#define OPENGLABSTRACTIONS_TEXTURE_H_

#include <glad/glad.h>

namespace opengl
{
	class Texture
	{
	public:
		enum Target
		{
			TARGET_TEXTURE_2D = GL_TEXTURE_2D,
			TARGET_PROXY_TEXTURE_2D = GL_PROXY_TEXTURE_2D,
			TARGET_TEXTURE_1D_ARRAY = GL_TEXTURE_1D_ARRAY,
			TARGET_PROXY_TEXTURE_1D_ARRAY = GL_PROXY_TEXTURE_1D_ARRAY,
			TARGET_TEXTURE_RECTANGLE = GL_TEXTURE_RECTANGLE,
			TARGET_PROXY_TEXTURE_RECTANGLE = GL_PROXY_TEXTURE_RECTANGLE,
			TARGET_TEXTURE_CUBE_MAP_POSITIVE_X = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
			TARGET_TEXTURE_CUBE_MAP_NEGATIVE_X = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
			TARGET_TEXTURE_CUBE_MAP_POSITIVE_Y = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
			TARGET_TEXTURE_CUBE_MAP_NEGATIVE_Y = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
			TARGET_TEXTURE_CUBE_MAP_POSITIVE_Z = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
			TARGET_TEXTURE_CUBE_MAP_NEGATIVE_Z = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
		};
		enum TexParam
		{
			TEX_PARAM_TEXTURE_WRAP_S = GL_TEXTURE_WRAP_S,
			TEX_PARAM_TEXTURE_WRAP_T = GL_TEXTURE_WRAP_T,
			TEX_PARAM_TEXTURE_MAG_FILTER = GL_TEXTURE_MAG_FILTER,
			TEX_PARAM_TEXTURE_MIN_FILTER = GL_TEXTURE_MIN_FILTER
		};
		enum TexParamValue
		{
			TEX_PARAM_VALUE_REPEAT = GL_REPEAT,
			TEX_PARAM_VALUE_LINEAR = GL_LINEAR,
			TEX_PARAM_VALUE_CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
			TEX_PARAM_VALUE_LINEAR_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR
		};
		enum InteralFormat
		{
			INTERNAL_FORMAT_DEPTH_COMPONENT = GL_DEPTH_COMPONENT,
			INTERNAL_FORMAT_DEPTH_STENCIL = GL_DEPTH_STENCIL,
			INTERNAL_FORMAT_RED = GL_RED,
			INTERNAL_FORMAT_RG = GL_RG,
			INTERNAL_FORMAT_RGB = GL_RGB,
			INTERNAL_FORMAT_RGBA = GL_RGBA
		};
		enum Format
		{
			FORMAT_RED = GL_RED,
			FORMAT_RG = GL_RG,
			FORMAT_RGB = GL_RGB,
			FORMAT_BGR = GL_BGR,
			FORMAT_RGBA = GL_RGBA,
			FORMAT_BGRA = GL_BGRA,
			FORMAT_RED_INTEGER = GL_RED_INTEGER,
			FORMAT_RG_INTEGER = GL_RG_INTEGER,
			FORMAT_RGB_INTEGER = GL_RGB_INTEGER,
			FORMAT_BGR_INTEGER = GL_BGR_INTEGER,
			FORMAT_RGBA_INTEGER = GL_RGBA_INTEGER,
			FORMAT_BGRA_INTEGER = GL_BGRA_INTEGER,
			FORMAT_STENCIL_INDEX = GL_STENCIL_INDEX,
			FORMAT_DEPTH_COMPONENT = GL_DEPTH_COMPONENT,
			FORMAT_DEPTH_STENCIL = GL_DEPTH_STENCIL
		};
		enum PixelType
		{
			PIXELTYPE_UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
			PIXELTYPE_BYTE = GL_BYTE,
			PIXELTYPE_UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
			PIXELTYPE_SHORT = GL_SHORT,
			PIXELTYPE_UNSIGNED_INT = GL_UNSIGNED_INT,
			PIXELTYPE_INT = GL_INT,
			PIXELTYPE_FLOAT = GL_FLOAT,
			PIXELTYPE_UNSIGNED_BYTE_3_3_2 = GL_UNSIGNED_BYTE_3_3_2,
			PIXELTYPE_UNSIGNED_BYTE_2_3_3_REV = GL_UNSIGNED_BYTE_2_3_3_REV,
			PIXELTYPE_UNSIGNED_SHORT_5_6_5 = GL_UNSIGNED_SHORT_5_6_5,
			PIXELTYPE_UNSIGNED_SHORT_5_6_5_REV = GL_UNSIGNED_SHORT_5_6_5_REV,
			PIXELTYPE_UNSIGNED_SHORT_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4,
			PIXELTYPE_UNSIGNED_SHORT_4_4_4_4_REV = GL_UNSIGNED_SHORT_4_4_4_4_REV,
			PIXELTYPE_UNSIGNED_SHORT_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1,
			PIXELTYPE_UNSIGNED_SHORT_1_5_5_5_REV = GL_UNSIGNED_SHORT_1_5_5_5_REV,
			PIXELTYPE_UNSIGNED_INT_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8,
			PIXELTYPE_UNSIGNED_INT_8_8_8_8_REV = GL_UNSIGNED_INT_8_8_8_8_REV,
			PIXELTYPE_UNSIGNED_INT_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2,
			PIXELTYPE_UNSIGNED_INT_2_10_10_10_REV = GL_UNSIGNED_INT_2_10_10_10_REV
		};

	public:
		Texture();
		Texture(const int color, const int width = 1, const int height = 1);
		Texture(const char* imagePath);
		Texture(const Target target, const int level, const InteralFormat internalFormat, const int width, int height, const int border, const Format format, const PixelType type, void* data);
		~Texture();

		void bind() const;
		void unBind() const;
		void bindToUnit(const int unit) const;

		void genMipMaps() const;
		void setParameter(TexParam param, TexParamValue value) const;

		const inline unsigned int getId() const { return id; };

		static void bindUnit(unsigned int id, unsigned short int unit);
	private:
		unsigned int id;
		int width, height;
	};
}

#endif // !OPENGLABSTRACTIONS_TEXTURE_H_
