#version 330 core

layout(location = 0) in vec4 a_pos;
layout(location = 1) in vec3 a_col;
layout(location = 2) in vec2 a_texCoord;

uniform mat4 u_pMatrix;
uniform mat4 u_vMatrix;
uniform mat4 u_tMatrix;

out vec3 v_col;
out vec2 v_texCoord;

void main() {
	gl_Position = u_pMatrix * u_vMatrix * u_tMatrix * a_pos;

	v_col = a_col;
	v_texCoord = a_texCoord;
}