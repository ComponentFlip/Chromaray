#version 330 core

in vec2 texCoords_pass;

uniform sampler2D texSampler;

void main() {
	gl_FragColor = texture2D(texSampler, texCoords_pass);
}