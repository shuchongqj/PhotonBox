#version 120

uniform vec3 color = vec3(0, 0, 0);

void main(){
	gl_FragColor = vec4(color, 1);
}