#ifndef OPENGLABSTRACTIONS_CONTEXT_H_
#define OPENGLABSTRACTIONS_CONTEXT_H_

#include <glad/glad.h>

namespace opengl
{
	class Context 
	{
	public:
		enum Settings
		{
			SETTINGS_BLEND = GL_BLEND,
			SETTINGS_DEPTH_TEST = GL_DEPTH_TEST,
			SETTINGS_MULTISAMPLE = GL_MULTISAMPLE,
			SETTINGS_DEBUG_OUTPUT = GL_DEBUG_OUTPUT,
			SETTINGS_DEBUG_OUTPUT_SYNCHRONOUS = GL_DEBUG_OUTPUT_SYNCHRONOUS
		};

		enum Clear
		{
			CLEAR_COLOR_BUFFER_BIT = GL_COLOR_BUFFER_BIT,
			CLEAR_DEPTH_BUFFER_BIT = GL_DEPTH_BUFFER_BIT,
			CLEAR_STENCIL_BUFFER_BIT = GL_STENCIL_BUFFER_BIT
		};

		enum Mode
		{
			MODE_POINTS = GL_POINTS, 
			MODE_LINE_STRIP = GL_LINE_STRIP, 
			MODE_LINE_LOOP = GL_LINE_LOOP, 
			MODE_LINES = GL_LINES, 
			MODE_LINE_STRIP_ADJACENCY = GL_LINE_STRIP_ADJACENCY, 
			MODE_LINES_ADJACENCY = GL_LINES_ADJACENCY, 
			MODE_TRIANGLE_STRIP = GL_TRIANGLE_STRIP, 
			MODE_TRIANGLE_FAN = GL_TRIANGLE_FAN, 
			MODE_TRIANGLES = GL_TRIANGLES, 
			MODE_TRIANGLE_STRIP_ADJACENCY = GL_TRIANGLE_STRIP_ADJACENCY,
			MODE_TRIANGLES_ADJACENCY = GL_TRIANGLES_ADJACENCY
		};

		enum Type
		{
			TYPE_UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
			TYPE_UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
			TYPE_UNSIGNED_INT = GL_UNSIGNED_INT
		};

		enum Factor
		{
			FACTOR_ZERO = GL_ZERO, 
			FACTOR_ONE = GL_ONE, 
			FACTOR_SRC_COLOR = GL_SRC_COLOR, 
			FACTOR_ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR, 
			FACTOR_DST_COLOR = GL_DST_COLOR, 
			FACTOR_ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR,
			FACTOR_SRC_ALPHA = GL_SRC_ALPHA,
			FACTOR_ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA,
			FACTOR_DST_ALPHA = GL_DST_ALPHA,
			FACTOR_ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA,
			FACTOR_CONSTANT_COLOR = GL_CONSTANT_COLOR,
			FACTOR_ONE_MINUS_CONSTANT_COLOR = GL_ONE_MINUS_CONSTANT_COLOR,
			FACTOR_CONSTANT_ALPHA = GL_CONSTANT_ALPHA,
			FACTOR_ONE_MINUS_CONSTANT_ALPHA = GL_ONE_MINUS_CONSTANT_ALPHA
		};

	public:
		static void clear(const int clear);
		static void clear(const Clear clear);
		static void clearColor(const float r, const float g, const float b, const float a);
		static void setViewPort(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height);
		static void enable(const Settings setting);
		static void disable(const Settings setting);
		static void blendFunc(const Factor sfactor, const Factor dfactor);
		static void draw(const Mode mode, const unsigned int count, const Type type, const void* offset);
		static void enableDebug();
	};
}

#endif // !OPENGLABSTRACTIONS_CONTEXT_H_