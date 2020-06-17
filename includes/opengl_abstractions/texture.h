#ifndef OPENGLABSTRACTIONS_TEXTURE_H_
#define OPENGLABSTRACTIONS_TEXTURE_H_

#include <glad/glad.h>

namespace opengl
{
	class texture
	{
	public:
		enum target
		{
			target_texture_2d = GL_TEXTURE_2D,
			target_proxy_texture_2d = GL_PROXY_TEXTURE_2D,
			target_texture_1d_array = GL_TEXTURE_1D_ARRAY,
			target_proxy_texture_1d_array = GL_PROXY_TEXTURE_1D_ARRAY,
			target_texture_rectangle = GL_TEXTURE_RECTANGLE,
			target_proxy_texture_rectangle = GL_PROXY_TEXTURE_RECTANGLE,
			target_texture_cube_map_positive_x = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
			target_texture_cube_map_negative_x = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
			target_texture_cube_map_positive_y = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
			target_texture_cube_map_negative_y = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
			target_texture_cube_map_positive_z = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
			target_texture_cube_map_negative_z = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
		};
		enum tex_param
		{
			tex_param_texture_wrap_s = GL_TEXTURE_WRAP_S,
			tex_param_texture_wrap_t = GL_TEXTURE_WRAP_T,
			tex_param_texture_mag_filter = GL_TEXTURE_MAG_FILTER,
			tex_param_texture_min_filter = GL_TEXTURE_MIN_FILTER
		};
		enum tex_param_value
		{
			tex_param_value_repeat = GL_REPEAT,
			tex_param_value_linear = GL_LINEAR,
			tex_param_value_clamp_to_edge = GL_CLAMP_TO_EDGE,
			tex_param_value_linear_mipmap_linear = GL_LINEAR_MIPMAP_LINEAR
		};
		enum interal_format
		{
			internal_format_depth_component = GL_DEPTH_COMPONENT,
			internal_format_depth_stencil = GL_DEPTH_STENCIL,
			internal_format_red = GL_RED,
			internal_format_rg = GL_RG,
			internal_format_rgb = GL_RGB,
			internal_format_rgba = GL_RGBA
		};
		enum format
		{
			format_red = GL_RED,
			format_rg = GL_RG,
			format_rgb = GL_RGB,
			format_bgr = GL_BGR,
			format_rgba = GL_RGBA,
			format_bgra = GL_BGRA,
			format_red_integer = GL_RED_INTEGER,
			format_rg_integer = GL_RG_INTEGER,
			format_rgb_integer = GL_RGB_INTEGER,
			format_bgr_integer = GL_BGR_INTEGER,
			format_rgba_integer = GL_RGBA_INTEGER,
			format_bgra_integer = GL_BGRA_INTEGER,
			format_stencil_index = GL_STENCIL_INDEX,
			format_depth_component = GL_DEPTH_COMPONENT,
			format_depth_stencil = GL_DEPTH_STENCIL
		};
		enum pixel_type
		{
			pixeltype_unsigned_byte = GL_UNSIGNED_BYTE,
			pixeltype_byte = GL_BYTE,
			pixeltype_unsigned_short = GL_UNSIGNED_SHORT,
			pixeltype_short = GL_SHORT,
			pixeltype_unsigned_int = GL_UNSIGNED_INT,
			pixeltype_int = GL_INT,
			pixeltype_float = GL_FLOAT,
			pixeltype_unsigned_byte_3_3_2 = GL_UNSIGNED_BYTE_3_3_2,
			pixeltype_unsigned_byte_2_3_3_rev = GL_UNSIGNED_BYTE_2_3_3_REV,
			pixeltype_unsigned_short_5_6_5 = GL_UNSIGNED_SHORT_5_6_5,
			pixeltype_unsigned_short_5_6_5_rev = GL_UNSIGNED_SHORT_5_6_5_REV,
			pixeltype_unsigned_short_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4,
			pixeltype_unsigned_short_4_4_4_4_rev = GL_UNSIGNED_SHORT_4_4_4_4_REV,
			pixeltype_unsigned_short_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1,
			pixeltype_unsigned_short_1_5_5_5_rev = GL_UNSIGNED_SHORT_1_5_5_5_REV,
			pixeltype_unsigned_int_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8,
			pixeltype_unsigned_int_8_8_8_8_rev = GL_UNSIGNED_INT_8_8_8_8_REV,
			pixeltype_unsigned_int_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2,
			pixeltype_unsigned_int_2_10_10_10_rev = GL_UNSIGNED_INT_2_10_10_10_REV
		};

	public:
		texture();
		texture(const int p_Color, const int p_Width = 1, const int p_Height = 1);
		texture(const char* p_ImagePath);
		texture(const target p_Target, const int p_Level, const interal_format p_InternalFormat, const int p_Width, int p_Height, const int p_Border, const format p_Format, const pixel_type p_Type, void* p_Data);
		~texture();

		void bind() const;
		void un_bind() const;
		void bind_to_unit(const int p_Unit) const;

		void gen_mipmaps() const;
		void set_parameter(tex_param p_Param, tex_param_value p_Value) const;

		const inline unsigned int get_id() const { return m_Id; };

		static void bind_unit(unsigned int p_Id, unsigned short int p_Unit);
	private:
		unsigned int m_Id;
		int m_Width, m_Height;
	};
}

#endif // !OPENGLABSTRACTIONS_TEXTURE_H_
