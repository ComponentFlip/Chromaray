#include "Material.hpp"

Material::Material(std::string name) 
	: m_Shader(Shader(readFile(Constants::SHADER_PATH + name + ".vert"), readFile(Constants::SHADER_PATH + name + ".frag"))) {}
