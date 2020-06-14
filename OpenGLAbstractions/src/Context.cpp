#include "../includes/Context.h"

namespace opengl
{
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
}