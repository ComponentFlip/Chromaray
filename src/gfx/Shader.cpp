#include "Shader.hpp"

Shader::Shader(std::string vertexSource, std::string fragmentSource) {
	unsigned int vertexShader = createShader(vertexSource, GL_VERTEX_SHADER);
	unsigned int fragmentShader = createShader(fragmentSource, GL_FRAGMENT_SHADER);

	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertexShader);
	glAttachShader(m_ID, fragmentShader);
	glLinkProgram(m_ID);

	int linked;
	glGetProgramiv(m_ID, GL_LINK_STATUS, &linked);
	if (!linked) {
		int length;
		char message[Constants::SHADER_ERRORSIZE];

		glGetProgramInfoLog(m_ID, Constants::SHADER_ERRORSIZE, &length, message);
		std::cout << "Failed to link program! \n" << message << std::endl;
	}
}

Shader::~Shader() {
	glDeleteProgram(m_ID);
}

void Shader::use() const {
	glUseProgram(m_ID);
}

void Shader::stop() const {
	glUseProgram(0);
}

unsigned int Shader::createShader(std::string source, unsigned int type) {
	unsigned int shader = glCreateShader(type);
	const char* cstrSource = source.c_str();

	glShaderSource(shader, 1, &cstrSource, NULL);
	glCompileShader(shader);

	int compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		int length;
		char message[Constants::SHADER_ERRORSIZE];

		glGetShaderInfoLog(shader, Constants::SHADER_ERRORSIZE, &length, message);
		std::cout << "Failed to compile shader! \n" << message << std::endl;
	}

	return shader;
}