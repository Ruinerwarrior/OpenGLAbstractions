#include "../includes/opengl_abstractions/context.h"

#include <string>

namespace opengl
{
	void APIENTRY gl_debug_output(GLenum p_Source,
		GLenum p_Type,
		GLuint p_Id,
		GLenum p_Severity,
		GLsizei p_Length,
		const GLchar* p_Message,
		const void* p_UserParam)
	{
		// ignore non-significant error/warning codes
		if (p_Id == 131169 || p_Id == 131185 || p_Id == 131218 || p_Id == 131204) return;

		std::string log = "---------------\n";
		log += "Debug message %i: %s\n";

		switch (p_Source)
		{
		case GL_DEBUG_SOURCE_API:             log += "Source: API\n"; break;
		case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   log += "Source: Window System\n"; break;
		case GL_DEBUG_SOURCE_SHADER_COMPILER: log += "Source: Shader Compiler\n"; break;
		case GL_DEBUG_SOURCE_THIRD_PARTY:     log += "Source: Third Party\n"; break;
		case GL_DEBUG_SOURCE_APPLICATION:     log += "Source: Application\n"; break;
		case GL_DEBUG_SOURCE_OTHER:           log += "Source: Other\n"; break;
		}

		switch (p_Type)
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

		switch (p_Severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         log += "Severity: high\n"; break;
		case GL_DEBUG_SEVERITY_MEDIUM:       log += "Severity: medium\n"; break;
		case GL_DEBUG_SEVERITY_LOW:          log += "Severity: low\n"; break;
		case GL_DEBUG_SEVERITY_NOTIFICATION: log += "Severity: notification\n"; break;
		}
		log += "\n";
		
		printf(log.c_str(), p_Id, p_Message);
	}

	void context::clear(const int p_Clear)
	{
		glClear(p_Clear);
	}

	void context::clear(const mask p_Clear)
	{
		glClear(p_Clear);
	}

	void context::clear_color(const float p_R, const float p_G, const float p_B, const float p_A)
	{
		glClearColor(p_R, p_G, p_B, p_A);
	}

	void context::set_viewport(const unsigned int p_X, const unsigned int p_Y, const unsigned int p_Width, const unsigned int p_Height)
	{
		glViewport(p_X, p_Y, p_Width, p_Height);
	}

	void context::enable(const settings p_Setting)
	{
		glEnable(p_Setting);
	}

	void context::disable(const settings p_Setting)
	{
		glDisable(p_Setting);
	}

	void context::blend_func(const factor p_Sfactor, const factor p_Dfactor)
	{
		glBlendFunc(p_Sfactor, p_Dfactor);
	}

	void context::draw(const mode p_Mode, const unsigned int p_Count, const type p_Type, const void* p_Offset)
	{
		glDrawElements(p_Mode, p_Count, p_Type, p_Offset);
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