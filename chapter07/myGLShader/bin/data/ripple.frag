#version 120
// simple fragment shader

// 'time' contains seconds since the program was linked.
uniform float time;
//uniform vec2 resolution; // Screen resolution
uniform sampler2DRect texture;
//uniform sampler2DRect tex2;

float radius = .5;

void main(void)
{
  	vec2 tc = gl_TexCoord[0].xy;
  	vec2 p = -1.0 + 2.0 * tc;
  	float len = length(p);
  	vec2 uv = tc + 2.0*(p/len)*cos(len*0.12-time*4.0);
  	vec3 col = texture2DRect(texture,uv).xyz;
  	gl_FragColor = vec4(col,1.0);  
}

