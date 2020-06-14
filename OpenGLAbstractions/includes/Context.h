#ifndef OPENGLABSTRACTIONS_CONTEXT_H_
#define OPENGLABSTRACTIONS_CONTEXT_H_

#include <glad/glad.h>

namespace opengl
{
	class Context 
	{
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

	public:
		static void clear(const Clear clear);
		static void clearColor(const float r, const float g, const float b, const float a);
		static void setViewPort(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height);
		static void enable(const Settings setting);
		static void disable(const Settings setting);
	};
}

#endif // !OPENGLABSTRACTIONS_CONTEXT_H_