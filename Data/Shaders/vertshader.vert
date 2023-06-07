varying out vec4 vert_pos;

void main()
{
    //transform vertex position
    vert_pos = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

    //transform texture coordinates
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;

    //forward the vertex colour
    gl_FrontColor = gl_Color;
}