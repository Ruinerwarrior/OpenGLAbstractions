#include "../includes/opengl_abstractions/context.h"

#include <string>

namespace opengl
{
	void APIENTRY gl_debug_output(GLenum p_source,
		GLenum p_type,
		GLuint p_id,
		GLenum p_severity,
		GLsizei p_length,
		const GLchar* p_message,
		const void* p_userparam)
	{
		// ignore non-significant error/warning codes
		if (p_id == 131169 || p_id == 131185 || p_id == 131218 || p_id == 131204) return;

		std::string log = "---------------\n";
		log += "Debug message %i: %s\n";

		switch (p_source)
		{
		case GL_DEBUG_SOURCE_API:             log += "Source: API\n"; break;
		case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   log += "Source: Window System\n"; break;
		case GL_DEBUG_SOURCE_SHADER_COMPILER: log += "Source: Shader Compiler\n"; break;
		case GL_DEBUG_SOURCE_THIRD_PARTY:     log += "Source: Third Party\n"; break;
		case GL_DEBUG_SOURCE_APPLICATION:     log += "Source: Application\n"; break;
		case GL_DEBUG_SOURCE_OTHER:           log += "Source: Other\n"; break;
		}

		switch (p_type)
		{
		case GL_DEBUG_TYPE_ERROR:               log += "Type: Error\n"; break;
		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: log += "Type: Deprecated Behaviour\n"; break;
		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  log += "Type: Undefined Behaviour\n"; break;
		case GL_DEBUG_TYPE_PORTABILITY:         log += "Type: Portability\n"; break;
		case GL_DEBUG_TYPE_PERFORMANCE:         log += "Type: Performance\n"; break;
		case GL_DEBUG_TYPE_MARKER:              log += "Type: Marker\n"; break;
		case GL_DEBUG_TYPE_PUSH_GROUP:          log += "Type: Push Group\n"; break;
		case GL_DEBUG_TYPE_POP_GROUP:           log += "Type: Pop Group\n"; break;
		case GL_DEBUG_TYPE_OTHER:               log += "Type: Other\n"; break;
		}

		switch (p_severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         log += "Severity: high\n"; break;
		case GL_DEBUG_SEVERITY_MEDIUM:       log += "Severity: medium\n"; break;
		case GL_DEBUG_SEVERITY_LOW:          log += "Severity: low\n"; break;
		case GL_DEBUG_SEVERITY_NOTIFICATION: log += "Severity: notification\n"; break;
		}
		log += "\n";
		
		printf(log.c_str(), p_id, p_message);
	}

	void context::clear(const int p_clear)
	{
		glClear(p_clear);
	}

	void context::clear(const mask p_clear)
	{
		glClear(p_clear);
	}

	void context::clear_color(const float p_r, const float p_g, const float p_b, const float p_a)
	{
		glClearColor(p_r, p_g, p_b, p_a);
	}

	void context::set_viewport(const unsigned int p_x, const unsigned int p_y, const unsigned int p_width, const unsigned int p_height)
	{
		glViewport(p_x, p_y, p_width, p_height);
	}

	void context::enable(const settings p_setting)
	{
		glEnable(p_setting);
	}

	void context::disable(const settings p_setting)
	{
		glDisable(p_setting);
	}

	void context::blend_func(const factor p_sfactor, const factor p_dfactor)
	{
		glBlendFunc(p_sfactor, p_dfactor);
	}

	void context::draw(const mode p_mode, const unsigned int p_count, const type p_type, const void* p_offset)
	{
		glDrawElements(p_mode, p_count, p_type, p_offset);
	}

	void context::enable_debug()
	{
		GLint flags;
		glGetIntegerv(GL_CONTEXT_FLAGS, &flags);

		if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
		{
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback(gl_debug_output, nullptr);
			glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
		}
	}
}