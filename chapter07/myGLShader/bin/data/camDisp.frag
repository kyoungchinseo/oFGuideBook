#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect video;

void main()
{
    // globalColor is being set inside the vertex shader.
    // the fragment color is then set to the globalColor.
	vec4 color = texture2DRect(video, gl_TexCoord[0].xy);

    gl_FragColor = color;
}