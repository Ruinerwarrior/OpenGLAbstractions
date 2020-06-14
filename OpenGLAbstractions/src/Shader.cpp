#include "../includes/Shader.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>


namespace opengl
{
	Shader::Shader(const char* vertPath, const char* fragPath)
	{
		createShader(vertPath, fragPath);
	}

	Shader::~Shader()
	{
		glUseProgram(0);
		glDeleteProgram(id);
	}

	void Shader::use() const
	{
		glUseProgram(id);
	}

	void Shader::unUse() const
	{
		glUseProgram(0);
	}

	void Shader::setBool(const char* name, const bool value) const
	{
		glUniform1i(glGetUniformLocation(id, name), (int)value);
	}
	void Shader::setInt(const char* name, const int value) const
	{
		glUniform1i(glGetUniformLocation(id, name), value);
	}
	void Shader::setInt(const char* name, const int* value, const int components) const
	{
		glUniform1iv(glGetUniformLocation(id, name), components, value);
	}
	void Shader::setFloat(const char* name, const float value) const
	{
		glUniform1f(glGetUniformLocation(id, name), value);
	}
	void Shader::setVec2(const char* name, const glm::vec2& value) const
	{
		glUniform2fv(glGetUniformLocation(id, name), 1, &value[0]);
	}
	void Shader::setVec3(const char* name, const glm::vec3& value) const
	{
		glUniform3fv(glGetUniformLocation(id, name), 1, &value[0]);
	}
	void Shader::setVec4(const char* name, const glm::vec4& value) const
	{
		glUniform4fv(glGetUniformLocation(id, name), 1, &value[0]);
	}
	void Shader::setMat2(const char* name, const glm::mat2& mat) const
	{
		glUniformMatrix2fv(glGetUniformLocation(id, name), 1, GL_FALSE, &mat[0][0]);
	}
	void Shader::setMat3(const char* name, const glm::mat3& mat) const
	{
		glUniformMatrix3fv(glGetUniformLocation(id, name), 1, GL_FALSE, &mat[0][0]);
	}
	void Shader::setMat4(const char* name, const float* value) const
	{
		glUniformMatrix4fv(glGetUniformLocation(id, name), 1, GL_FALSE, value);
	}

	void Shader::createShader(const char* vertPath, const char* fragPath)
	{
		unsigned int vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

		std::ifstream vertStream;
		std::ifstream fragStream;

		vertStream.open(vertPath);
		fragStream.open(fragPath);

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

		id = glCreateProgram();
		glAttachShader(id, vertexShaderId);
		glAttachShader(id, fragmentShaderId);
		glLinkProgram(id);

		glGetProgramiv(id, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(id, 512, NULL, infoLog);
			// ENGINE_LOG_ERROR("ERROR::SHADER::LINKING_FAILED\n {}\n", infoLog);
		}

		glDeleteShader(vertexShaderId);
		glDeleteShader(fragmentShaderId);
	}
}