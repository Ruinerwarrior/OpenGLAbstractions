#ifndef OPENGLABSTRACTIONS_CONTEXT_H_
#define OPENGLABSTRACTIONS_CONTEXT_H_

#include <glad/glad.h>

namespace opengl
{
	class context 
	{
	public:
		enum settings
		{
			settings_blend = GL_BLEND,
			settings_depth_test = GL_DEPTH_TEST,
			settings_multisample = GL_MULTISAMPLE,
			settings_debug_output = GL_DEBUG_OUTPUT,
			settings_debug_output_synchronous = GL_DEBUG_OUTPUT_SYNCHRONOUS
		};

		enum mask
		{
			clear_color_buffer_bit = GL_COLOR_BUFFER_BIT,
			clear_depth_buffer_bit = GL_DEPTH_BUFFER_BIT,
			clear_stencil_buffer_bit = GL_STENCIL_BUFFER_BIT
		};

		enum mode
		{
			mode_points = GL_POINTS, 
			mode_line_strip = GL_LINE_STRIP, 
			mode_line_loop = GL_LINE_LOOP, 
			mode_lines = GL_LINES, 
			mode_line_strip_adjacency = GL_LINE_STRIP_ADJACENCY, 
			mode_lines_adjacency = GL_LINES_ADJACENCY, 
			mode_triangle_strip = GL_TRIANGLE_STRIP, 
			mode_triangle_fan = GL_TRIANGLE_FAN, 
			mode_triangles = GL_TRIANGLES, 
			mode_triangle_strip_adjacency = GL_TRIANGLE_STRIP_ADJACENCY,
			mode_triangles_adjacency = GL_TRIANGLES_ADJACENCY
		};

		enum type
		{
			type_unsigned_byte = GL_UNSIGNED_BYTE,
			type_unsigned_short = GL_UNSIGNED_SHORT,
			type_unsigned_int = GL_UNSIGNED_INT
		};

		enum factor
		{
			factor_zero = GL_ZERO, 
			factor_one = GL_ONE, 
			factor_src_color = GL_SRC_COLOR, 
			factor_one_minus_src_color = GL_ONE_MINUS_SRC_COLOR, 
			factor_dst_color = GL_DST_COLOR, 
			factor_one_minus_dst_color = GL_ONE_MINUS_DST_COLOR,
			factor_src_alpha = GL_SRC_ALPHA,
			factor_one_minus_src_alpha = GL_ONE_MINUS_SRC_ALPHA,
			factor_dst_alpha = GL_DST_ALPHA,
			factor_one_minus_dst_alpha = GL_ONE_MINUS_DST_ALPHA,
			factor_constant_color = GL_CONSTANT_COLOR,
			factor_one_minus_constant_color = GL_ONE_MINUS_CONSTANT_COLOR,
			factor_constant_alpha = GL_CONSTANT_ALPHA,
			factor_one_minus_constant_alpha = GL_ONE_MINUS_CONSTANT_ALPHA
		};

	public:
		static void clear(const int p_clear);
		static void clear(const mask p_clear);
		static void clear_color(const float p_r, const float p_g, const float p_b, const float p_a);
		static void set_viewport(const unsigned int p_x, const unsigned int p_y, const unsigned int p_width, const unsigned int p_height);
		static void enable(const settings p_setting);
		static void disable(const settings p_setting);
		static void blend_func(const factor p_sFactor, const factor p_dFactor);
		static void draw(const mode p_mode, const unsigned int p_count, const type p_type, const void* p_offset);
		static void enable_debug();
	};
}

#endif // !OPENGLABSTRACTIONS_CONTEXT_H_