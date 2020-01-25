#version 330 core

in vec4 position;
in vec2 texCoords;

out vec2 texCoords_pass;

void main() {
	gl_Position = position;
	texCoords_pass = texCoords;
}