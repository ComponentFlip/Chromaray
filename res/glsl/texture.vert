#version 330 core

in vec4 a_pos;
in vec2 a_texCoords;

uniform mat4 u_pMatrix;
uniform mat4 u_vMatrix;
uniform mat4 u_tMatrix;

out vec2 texCoords_pass;

void main() {
	gl_Position = u_pMatrix * u_vMatrix * u_tMatrix * a_pos;
	texCoords_pass = a_texCoords;
}