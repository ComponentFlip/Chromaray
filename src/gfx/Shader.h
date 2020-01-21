#pragma once

#include <GLEW/glew.h>

#include <iostream>
#include <string>

#include "../chromaray.h"

class Shader {
public:
	Shader(std::string vertexSource, std::string fragmentSource);
	~Shader();

	void use() const;
	void stop() const;
private:
	unsigned int m_ID;

	unsigned int createShader(std::string source, unsigned int type);
};