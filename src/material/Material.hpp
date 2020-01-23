#pragma once

#include <string>

#include "../FileLoader.hpp"
#include "../gfx/Shader.hpp"

class Material {
public:
	Material(std::string name);

	void useShader() const;
protected:
	Shader m_Shader;
	virtual void bindAllAttribs() = 0; 
};