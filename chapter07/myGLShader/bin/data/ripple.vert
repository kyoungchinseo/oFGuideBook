#version 120


//uniform float time;

// simple vertex shader

void main()
{
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_Position = ftransform();	
	
}