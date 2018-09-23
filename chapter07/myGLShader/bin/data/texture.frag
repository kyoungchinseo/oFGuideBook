#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect texture;

void main()
{
	vec4 color = texture2DRect(texture, gl_TexCoord[0].xy);

	gl_FragColor = color;
}
