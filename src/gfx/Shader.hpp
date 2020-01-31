#pragma once

#include <GL/glew.h>

#include <iostream>
#include <string>

#include "../chromaray.hpp"
#include "../util/Matrix4f.hpp"

class Shader {
public:
	Shader(std::string vertexSource, std::string fragmentSource);
	~Shader();

	void bindAttribute(unsigned pointer, const char* name) const;
	unsigned getUniformLocation(const char* name) const;

	void setMatrixUniform(Matrix4f matrix, const char* locationName) const;

	void use() const;
	void stop() const;
private:
	unsigned m_ID;

	unsigned createShader(std::string source, unsigned type);
};