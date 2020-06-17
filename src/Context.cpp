#include "../includes/opengl_abstractions/Context.h"

#include <string>

namespace opengl
{
	void APIENTRY glDebugOutput(GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* userParam)
	{
		// ignore non-significant error/warning codes
		if (id == 131169 || id == 131185 || id == 131218 || id == 131204) return;

		std::string log = "---------------\n";
		log += "Debug message %i: %s\n";

		switch (source)
		{
		case GL_DEBUG_SOURCE_API:             log += "Source: API\n"; break;
		case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   log += "Source: Window System\n"; break;
		case GL_DEBUG_SOURCE_SHADER_COMPILER: log += "Source: Shader Compiler\n"; break;
		case GL_DEBUG_SOURCE_THIRD_PARTY:     log += "Source: Third Party\n"; break;
		case GL_DEBUG_SOURCE_APPLICATION:     log += "Source: Application\n"; break;
		case GL_DEBUG_SOURCE_OTHER:           log += "Source: Other\n"; break;
		}

		switch (type)
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

		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         log += "Severity: high\n"; break;
		case GL_DEBUG_SEVERITY_MEDIUM:       log += "Severity: medium\n"; break;
		case GL_DEBUG_SEVERITY_LOW:          log += "Severity: low\n"; break;
		case GL_DEBUG_SEVERITY_NOTIFICATION: log += "Severity: notification\n"; break;
		}
		log += "\n";
		
		printf(log.c_str(), id, message);
	}

	void Context::clear(const int clear)
	{
		glClear(clear);
	}

	void Context::clear(const Clear clear)
	{
		glClear(clear);
	}

	void Context::clearColor(const float r, const float g, const float b, const float a)
	{
		glClearColor(r, g, b, a);
	}

	void Context::setViewPort(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height)
	{
		glViewport(x, y, width, height);
	}

	void Context::enable(const Settings setting)
	{
		glEnable(setting);
	}

	void Context::disable(const Settings setting)
	{
		glDisable(setting);
	}

	void Context::blendFunc(const Factor sfactor, const Factor dfactor)
	{
		glBlendFunc(sfactor, dfactor);
	}

	void Context::draw(const Mode mode, const unsigned int count, const Type type, const void* offset)
	{
		glDrawElements(mode, count, type, offset);
	}

	void Context::enableDebug()
	{
		GLint flags;
		glGetIntegerv(GL_CONTEXT_FLAGS, &flags);

		if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
		{
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback(glDebugOutput, nullptr);
			glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
		}
	}
}