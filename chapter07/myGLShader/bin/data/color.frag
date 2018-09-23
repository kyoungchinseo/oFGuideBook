#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

void main()
{
	float windowWidth = 1024.0;
    float windowHeight = 768.0;
 
    float r = gl_FragCoord.x / windowWidth;
    float g = gl_FragCoord.y / windowHeight;
    float b = 1.0;
    float a = gl_FragCoord.x / windowWidth;
	gl_FragColor = vec4(r,g,b,1);
}
