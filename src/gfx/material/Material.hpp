#pragma once

#include <string>

#include "../../FileLoader.hpp"
#include "../gl/Shader.hpp"

class Material {
public:
	Material(std::string name);
	
	void bindAttribute(int position, std::string name) const;
	void bindUniform(glm::mat4 matrix, std::string name) const;

	virtual void prepare() const;
	void stop() const;
protected:
	Shader m_Shader;
};