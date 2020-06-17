#include "../includes/opengl_abstractions/shader.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>


namespace opengl
{
	shader::shader(const char* p_VertPath, const char* p_FragPath)
	{
		create_shader(p_VertPath, p_FragPath);
	}

	shader::~shader()
	{
		glUseProgram(0);
		glDeleteProgram(m_Id);
	}

	void shader::use() const
	{
		glUseProgram(m_Id);
	}

	void shader::un_use() const
	{
		glUseProgram(0);
	}

	void shader::set_bool(const char* p_Name, const bool p_Value) const
	{
		glUniform1i(glGetUniformLocation(m_Id, p_Name), (int)p_Value);
	}
	void shader::set_int(const char* p_Name, const int p_Value) const
	{
		glUniform1i(glGetUniformLocation(m_Id, p_Name), p_Value);
	}
	void shader::set_int(const char* p_Name, const int* p_Value, const int p_Components) const
	{
		glUniform1iv(glGetUniformLocation(m_Id, p_Name), p_Components, p_Value);
	}
	void shader::set_float(const char* p_Name, const float p_Value) const
	{
		glUniform1f(glGetUniformLocation(m_Id, p_Name), p_Value);
	}
	void shader::set_vec2(const char* p_Name, const glm::vec2& p_Value) const
	{
		glUniform2fv(glGetUniformLocation(m_Id, p_Name), 1, &p_Value[0]);
	}
	void shader::set_vec3(const char* p_Name, const glm::vec3& p_Value) const
	{
		glUniform3fv(glGetUniformLocation(m_Id, p_Name), 1, &p_Value[0]);
	}
	void shader::set_vec4(const char* p_Name, const glm::vec4& p_Value) const
	{
		glUniform4fv(glGetUniformLocation(m_Id, p_Name), 1, &p_Value[0]);
	}
	void shader::set_mat2(const char* p_Name, const glm::mat2& p_Value) const
	{
		glUniformMatrix2fv(glGetUniformLocation(m_Id, p_Name), 1, GL_FALSE, &p_Value[0][0]);
	}
	void shader::set_mat3(const char* p_Name, const glm::mat3& p_Value) const
	{
		glUniformMatrix3fv(glGetUniformLocation(m_Id, p_Name), 1, GL_FALSE, &p_Value[0][0]);
	}
	void shader::set_mat4(const char* p_Name, const float* p_Value) const
	{
		glUniformMatrix4fv(glGetUniformLocation(m_Id, p_Name), 1, GL_FALSE, p_Value);
	}

	void shader::create_shader(const char* p_VertPath, const char* p_FragPath)
	{
		unsigned int vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

		std::ifstream vertStream;
		std::ifstream fragStream;

		vertStream.open(p_VertPath);
		fragStream.open(p_FragPath);

		std::stringstream vertSource;
		std::stringstream fragSource;

		if (!vertStream)
			std::cout << "not able to load 'default.vert'" << std::endl;

		if (!fragStream)
			std::cout << "not able to load 'default.frag'" << std::endl;

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

		m_Id = glCreateProgram();
		glAttachShader(m_Id, vertexShaderId);
		glAttachShader(m_Id, fragmentShaderId);
		glLinkProgram(m_Id);

		glGetProgramiv(m_Id, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(m_Id, 512, NULL, infoLog);
			// ENGINE_LOG_ERROR("ERROR::SHADER::LINKING_FAILED\n {}\n", infoLog);
		}

		glDeleteShader(vertexShaderId);
		glDeleteShader(fragmentShaderId);
	}
}