#type vertex
#version 330     

layout (location = 0) in vec2 position;


uniform mat4 mvp;
uniform mat4 ortho;

void main()
{
    gl_Position = ortho * mvp * vec4(position, 0, 1);
}


#type fragment
#version 330 

out vec4 outColor;

uniform vec4 color;

void main()
{   
    outColor = color;
}