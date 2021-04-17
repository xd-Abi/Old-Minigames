#type vertex
#version 330     

layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoords;

out vec2 outTexCoords;

uniform mat4 mvp;

void main()
{
    gl_Position = mvp * vec4(position, 0, 1);
    outTexCoords = texCoords;
}


#type fragment
#version 330 

in vec2 outTexCoords;

out vec4 outColor;

uniform float use_color;
uniform vec4 color;
uniform float use_texture;
uniform sampler2D sampler;

void main()
{   
    outColor = vec4(1,1,1,1);

    if (use_color == 1)
    {
        outColor = color;
    } 
    else if (use_texture == 1)
    {
        outColor = texture(sampler, outTexCoords);
    }
}