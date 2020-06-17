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
	class shader
	{
	public:
		shader(const char* p_VertPath, const char* p_FragPath);
		~shader();

		void use() const;
		void un_use() const;

		void set_bool(const char* p_Name, const bool p_Value) const;
		void set_int(const char* p_Name, const int p_Value) const;
		void set_int(const char* p_Name, const int* p_Value, int components) const;
		void set_float(const char* p_Name, const float p_Value) const;
		void set_vec2(const char* p_Name, const glm::vec2& p_Value) const;
		void set_vec3(const char* p_Name, const glm::vec3& p_Value) const;
		void set_vec4(const char* p_Name, const glm::vec4& p_Value) const;
		void set_mat2(const char* p_Name, const glm::mat2& p_Value) const;
		void set_mat3(const char* p_Name, const glm::mat3& p_Value) const;
		void set_mat4(const char* p_Name, const float* p_Value) const;

	private:
		void create_shader(const char* p_VertPath, const char* p_FragPath);

	private:
		unsigned int m_Id;
	};
}

#endif // !OPENGLABSTRACTIONS_SHADER_H_
