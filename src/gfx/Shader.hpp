#pragma once

#include <GLEW/glew.h>

#include <iostream>
#include <string>

#include "../chromaray.hpp"

class Shader {
public:
	Shader(std::string vertexSource, std::string fragmentSource);
	~Shader();

	void bindAttribute(unsigned int pointer, const char* name) const;
	int getUniformLocation(const char* name) const;

	void use() const;
	void stop() const;
private:
	unsigned int m_ID;

	unsigned int createShader(std::string source, unsigned int type);
};