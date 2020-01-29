#include "Shader.hpp"

Shader::Shader(std::string vertexSource, std::string fragmentSource) {
	unsigned vertexShader = createShader(vertexSource, GL_VERTEX_SHADER);
	unsigned fragmentShader = createShader(fragmentSource, GL_FRAGMENT_SHADER);

	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertexShader);
	glAttachShader(m_ID, fragmentShader);
	glLinkProgram(m_ID);

	int linked;
	glGetProgramiv(m_ID, GL_LINK_STATUS, &linked);
	if (!linked) {
		int length;
		char message[Constants::SHADER_ERROR_SIZE];

		glGetProgramInfoLog(m_ID, Constants::SHADER_ERROR_SIZE, &length, message);
		std::cout << "Failed to link program! \n" << message << std::endl;
	}
}

Shader::~Shader() {
	glDeleteProgram(m_ID);
}

void Shader::bindAttribute(unsigned pointer, const char* name) const {
	glBindAttribLocation(m_ID, pointer, name);
}

int Shader::getUniformLocation(const char* name) const {
	return glGetUniformLocation(m_ID, name);
}

void Shader::use() const {
	glUseProgram(m_ID);
}

void Shader::stop() const {
	glUseProgram(0);
}

unsigned Shader::createShader(std::string source, unsigned type) {
	unsigned shader = glCreateShader(type);
	const char* cstrSource = source.c_str();

	glShaderSource(shader, 1, &cstrSource, NULL);
	glCompileShader(shader);

	int compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		int length;
		char message[Constants::SHADER_ERROR_SIZE];

		glGetShaderInfoLog(shader, Constants::SHADER_ERROR_SIZE, &length, message);
		std::cout << "Failed to compile shader! \n" << message << std::endl;
	}

	return shader;
}