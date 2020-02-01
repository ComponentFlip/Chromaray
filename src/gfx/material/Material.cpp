#include "Material.hpp"

Material::Material(std::string name) 
	: m_Shader(Shader(readFile(Constants::SHADER_PATH + name + ".vert")
	, readFile(Constants::SHADER_PATH + name + ".frag"))) 
{}

void Material::bindAttribute(int position, std::string name) const {
	m_Shader.bindAttribute(position, name.c_str());
}

void Material::bindUniform(glm::mat4 matrix, std::string name) const {
	m_Shader.setMatrixUniform(matrix, name.c_str());
}

void Material::prepare() const {
	m_Shader.use();
}