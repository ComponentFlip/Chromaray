#version 330 core

in vec3 v_col;
in vec2 v_texCoord;

uniform sampler2D u_texSampler;

void main() {
	vec4 colour = vec4(v_col, 1.0f);
	vec4 texture = texture2D(u_texSampler, v_texCoord);

	gl_FragColor = colour * texture;
}