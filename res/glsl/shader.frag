#version 330 core

in vec3 v_col;

void main() {
	gl_FragColor = vec4(v_col, 1.0f);
}