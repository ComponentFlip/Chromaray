#pragma once

#include <string>

#include "../FileLoader.hpp"
#include "../gfx/Shader.hpp"
#include "../util/Matrix4f.hpp"

class Material {
public:
	Material(std::string name);
	
	const Shader m_Shader;
protected:
	virtual void bindAllAttribs() = 0; 
};