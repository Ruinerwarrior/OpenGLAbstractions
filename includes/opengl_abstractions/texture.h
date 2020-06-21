#ifndef OPENGLABSTRACTIONS_TEXTURE_H_
#define OPENGLABSTRACTIONS_TEXTURE_H_

#include <glad/glad.h>

namespace opengl
{
	class texture
	{
	public:
		enum class target : GLenum
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
		enum class tex_param : GLenum
		{
			tex_param_texture_wrap_s = GL_TEXTURE_WRAP_S,
			tex_param_texture_wrap_t = GL_TEXTURE_WRAP_T,
			tex_param_texture_mag_filter = GL_TEXTURE_MAG_FILTER,
			tex_param_texture_min_filter = GL_TEXTURE_MIN_FILTER
		};
		enum tex_param_value : GLint
		{
			tex_param_value_repeat = GL_REPEAT,
			tex_param_value_linear = GL_LINEAR,
			tex_param_value_clamp_to_edge = GL_CLAMP_TO_EDGE,
			tex_param_value_linear_mipmap_linear = GL_LINEAR_MIPMAP_LINEAR
		};
		enum interal_format : GLint
		{
			internal_format_depth_component = GL_DEPTH_COMPONENT,
			internal_format_depth_stencil = GL_DEPTH_STENCIL,
			internal_format_red = GL_RED,
			internal_format_rg = GL_RG,
			internal_format_rgb = GL_RGB,
			internal_format_rgba = GL_RGBA
		};
		enum format : GLenum
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
		enum pixel_type : GLenum
		{
			pixel_type_unsigned_byte = GL_UNSIGNED_BYTE,
			pixel_type_byte = GL_BYTE,
			pixel_type_unsigned_short = GL_UNSIGNED_SHORT,
			pixel_type_short = GL_SHORT,
			pixel_type_unsigned_int = GL_UNSIGNED_INT,
			pixel_type_int = GL_INT,
			pixel_type_float = GL_FLOAT,
			pixel_type_unsigned_byte_3_3_2 = GL_UNSIGNED_BYTE_3_3_2,
			pixel_type_unsigned_byte_2_3_3_rev = GL_UNSIGNED_BYTE_2_3_3_REV,
			pixel_type_unsigned_short_5_6_5 = GL_UNSIGNED_SHORT_5_6_5,
			pixel_type_unsigned_short_5_6_5_rev = GL_UNSIGNED_SHORT_5_6_5_REV,
			pixel_type_unsigned_short_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4,
			pixel_type_unsigned_short_4_4_4_4_rev = GL_UNSIGNED_SHORT_4_4_4_4_REV,
			pixel_type_unsigned_short_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1,
			pixel_type_unsigned_short_1_5_5_5_rev = GL_UNSIGNED_SHORT_1_5_5_5_REV,
			pixel_type_unsigned_int_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8,
			pixel_type_unsigned_int_8_8_8_8_rev = GL_UNSIGNED_INT_8_8_8_8_REV,
			pixel_type_unsigned_int_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2,
			pixel_type_unsigned_int_2_10_10_10_rev = GL_UNSIGNED_INT_2_10_10_10_REV
		};

	public:
		texture() = default;
		~texture();

		void create();
		void create(const int p_color, const int p_width = 1, const int p_height = 1);
		void create(const char* p_imagepath);
		void create(const target p_target, const int p_level, const interal_format p_internalformat, const int p_width, int p_height, const int p_border, const format p_format, const pixel_type p_type, void* p_data);

		void bind() const;
		void un_bind() const;
		void bind_to_unit(const int p_unit) const;

		void gen_mipmaps() const;
		void set_parameter(tex_param p_param, tex_param_value p_value) const;

		const inline unsigned int get_id() const { return m_id; };

		static void bind_unit(unsigned int p_id, unsigned short int p_unit);
	private:
		unsigned int m_id = 0;
		int m_width = 0;
		int m_height = 0;
	};
}

#endif // !OPENGLABSTRACTIONS_TEXTURE_H_
