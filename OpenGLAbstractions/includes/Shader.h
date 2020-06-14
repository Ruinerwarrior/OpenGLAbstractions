#ifndef OPENGLABSTRACTIONS_SHADER_H_
#define OPENGLABSTRACTIONS_SHADER_H_

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat2x2.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>

namespace opengl
{
	class Shader
	{
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		void use() const;
		void unUse() const;

		void setBool(const char* name, const bool value) const;
		void setInt(const char* name, const int value) const;
		void setInt(const char* name, const int* value, int components) const;
		void setFloat(const char* name, const float value) const;
		void setVec2(const char* name, const glm::vec2& value) const;
		void setVec3(const char* name, const glm::vec3& value) const;
		void setVec4(const char* name, const glm::vec4& value) const;
		void setMat2(const char* name, const glm::mat2& mat) const;
		void setMat3(const char* name, const glm::mat3& mat) const;
		void setMat4(const char* name, const float* value) const;

	private:
		void createShader(const char* vertPath, const char* fragPath);

	private:
		unsigned int id;
	};
}

#endif // !OPENGLABSTRACTIONS_SHADER_H_
