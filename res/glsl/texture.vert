#version 330 core

in vec4 position;
in vec2 texCoords;

uniform mat4 u_tMatrix;

out vec2 texCoords_pass;

void main() {
	gl_Position = u_tMatrix * position;
	texCoords_pass = texCoords;
}