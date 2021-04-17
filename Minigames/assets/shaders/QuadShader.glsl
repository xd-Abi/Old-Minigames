#type vertex
#version 330     

layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoords;

uniform mat4 mvp;

void main()
{
    gl_Position = mvp * vec4(position, 0, 1);
}


#type fragment
#version 330 

void main()
{
    gl_FragColor = vec4(1,0,0,1);
}