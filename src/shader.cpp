#include "../includes/opengl_abstractions/shader.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>


namespace opengl
{
	shader::~shader()
	{
		glUseProgram(0);
		glDeleteProgram(m_id);
	}

	void shader::create(const char* p_vertPath, const char* p_fragPath)
	{
		create_shader(p_vertPath, p_fragPath);
	}

	void shader::use() const
	{
		glUseProgram(m_id);
	}

	void shader::un_use() const
	{
		glUseProgram(0);
	}

	void shader::set_bool(const char* p_name, const bool p_value) const
	{
		glUniform1i(glGetUniformLocation(m_id, p_name), (int)p_value);
	}
	void shader::set_int(const char* p_name, const int p_value) const
	{
		glUniform1i(glGetUniformLocation(m_id, p_name), p_value);
	}
	void shader::set_int(const char* p_name, const int* p_value, const int p_Components) const
	{
		glUniform1iv(glGetUniformLocation(m_id, p_name), p_Components, p_value);
	}
	void shader::set_float(const char* p_name, const float p_value) const
	{
		glUniform1f(glGetUniformLocation(m_id, p_name), p_value);
	}
	void shader::set_vec2(const char* p_name, const glm::vec2& p_value) const
	{
		glUniform2fv(glGetUniformLocation(m_id, p_name), 1, &p_value[0]);
	}
	void shader::set_vec3(const char* p_name, const glm::vec3& p_value) const
	{
		glUniform3fv(glGetUniformLocation(m_id, p_name), 1, &p_value[0]);
	}
	void shader::set_vec4(const char* p_name, const glm::vec4& p_value) const
	{
		glUniform4fv(glGetUniformLocation(m_id, p_name), 1, &p_value[0]);
	}
	void shader::set_mat2(const char* p_name, const glm::mat2& p_value) const
	{
		glUniformMatrix2fv(glGetUniformLocation(m_id, p_name), 1, GL_FALSE, &p_value[0][0]);
	}
	void shader::set_mat3(const char* p_name, const glm::mat3& p_value) const
	{
		glUniformMatrix3fv(glGetUniformLocation(m_id, p_name), 1, GL_FALSE, &p_value[0][0]);
	}
	void shader::set_mat4(const char* p_name, const float* p_value) const
	{
		glUniformMatrix4fv(glGetUniformLocation(m_id, p_name), 1, GL_FALSE, p_value);
	}

	void shader::create_shader(const char* p_vertPath, const char* p_fragPath)
	{
		unsigned int vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

		std::ifstream vertStream;
		std::ifstream fragStream;

		vertStream.open(p_vertPath);
		fragStream.open(p_fragPath);

		std::stringstream vertSource;
		std::stringstream fragSource;

		if (!vertStream)
			std::cout << "not able to load 'default.vert' \n";

		if (!fragStream)
			std::cout << "not able to load 'default.frag' \n";

		vertSource << vertStream.rdbuf();
		fragSource << fragStream.rdbuf();

		std::string vsStr = vertSource.str();
		std::string fsStr = fragSource.str();

		const char* vs = vsStr.c_str();
		const char* fs = fsStr.c_str();

		glShaderSource(vertexShaderId, 1, &vs, NULL);
		glShaderSource(fragmentShaderId, 1, &fs, NULL);

		int  success;
		char infoLog[512];
		glCompileShader(vertexShaderId);
		glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShaderId, 512, NULL, infoLog);
			// ENGINE_LOG_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n {}\n", infoLog);
		}
		glCompileShader(fragmentShaderId);
		glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShaderId, 512, NULL, infoLog);
			// ENGINE_LOG_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n {}\n", infoLog);
		}

		m_id = glCreateProgram();
		glAttachShader(m_id, vertexShaderId);
		glAttachShader(m_id, fragmentShaderId);
		glLinkProgram(m_id);

		glGetProgramiv(m_id, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(m_id, 512, NULL, infoLog);
			// ENGINE_LOG_ERROR("ERROR::SHADER::LINKING_FAILED\n {}\n", infoLog);
		}

		glDeleteShader(vertexShaderId);
		glDeleteShader(fragmentShaderId);
	}
}