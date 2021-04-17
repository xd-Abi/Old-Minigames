#type vertex
#version 330     

layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoords;

out vec2 outTexCoords;

uniform mat4 mvp;
uniform mat4 ortho;

void main()
{
    gl_Position = ortho * mvp * vec4(position, 0, 1);
    outTexCoords = texCoords;
}


#type fragment
#version 330 

in vec2 outTexCoords;

out vec4 outColor;

uniform sampler2D sampler;

void main()
{   
    outColor = texture(sampler, outTexCoords);
}