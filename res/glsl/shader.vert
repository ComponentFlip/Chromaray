#version 330 core

layout(location = 0) in vec4 a_pos;
layout(location = 1) in vec3 a_col;
layout(location = 2) in vec2 a_texCoord;

out vec3 v_col;
out vec2 v_texCoord;

void main() {
	gl_Position = a_pos;
	v_col = a_col;
	v_texCoord = a_texCoord;
}