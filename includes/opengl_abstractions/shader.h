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
		shader() = default;
		~shader();

		void create(const char* p_vertPath, const char* p_fragPath);

		void use() const;
		void un_use() const;

		void set_bool(const char* p_name, const bool p_value) const;
		void set_int(const char* p_name, const int p_value) const;
		void set_int(const char* p_name, const int* p_value, int components) const;
		void set_float(const char* p_name, const float p_value) const;
		void set_vec2(const char* p_name, const glm::vec2& p_value) const;
		void set_vec3(const char* p_name, const glm::vec3& p_value) const;
		void set_vec4(const char* p_name, const glm::vec4& p_value) const;
		void set_mat2(const char* p_name, const glm::mat2& p_value) const;
		void set_mat3(const char* p_name, const glm::mat3& p_value) const;
		void set_mat4(const char* p_name, const float* p_value) const;

	private:
		void create_shader(const char* p_vertPath, const char* p_fragPath);

	private:
		unsigned int m_id = 0;
	};
}

#endif // !OPENGLABSTRACTIONS_SHADER_H_
