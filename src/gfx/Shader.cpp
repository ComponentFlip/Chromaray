#include "Shader.h"

Shader::Shader(std::string vertexSource, std::string fragmentSource) {
	unsigned int vertexShader = createShader(vertexSource, GL_VERTEX_SHADER);
	unsigned int fragmentShader = createShader(fragmentSource, GL_FRAGMENT_SHADER);

	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertexShader);
	glAttachShader(m_ID, fragmentShader);
	glLinkProgram(m_ID);

	int linked;
	glGetProgramiv(m_ID, GL_LINK_STATUS, &linked);
	if (linked == GL_FALSE) {
		int length;
		char message[G_SHADER_ERRORSIZE];
		glGetProgramInfoLog(m_ID, G_SHADER_ERRORSIZE, &length, message);

		std::cout << "Failed to link program! " << message << std::endl;
	}
}

Shader::~Shader() {
	glDeleteProgram(m_ID);
}

void Shader::use() {
	glUseProgram(m_ID);
}

void Shader::stop() {
	glUseProgram(0);
}

unsigned int Shader::createShader(std::string source, unsigned int type) {
	unsigned int shader = glCreateShader(type);
	const char* cstrSource = source.c_str();

	glShaderSource(shader, 1, &cstrSource, NULL);
	glCompileShader(shader);

	int compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (compiled == GL_FALSE) {
		int length;
		char message[G_SHADER_ERRORSIZE];
		glGetShaderInfoLog(shader, G_SHADER_ERRORSIZE, &length, message);

		std::cout << "Failed to compile shader! " << message << std::endl;
	}

	return shader;
}