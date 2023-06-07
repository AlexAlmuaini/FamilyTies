varying in vec4 vert_pos;

uniform sampler2D texture;
uniform bool hasTexture;
uniform vec2 lightPos;

void main()
{
    //ambient light
    vec4 ambLight = vec4(0.04, 0.02, 0.02, 1);

    //convert light to view coords
    lightPos = (gl_ModelViewProjectionMatrix * vec4(lightPos, 0, 1)).xy;

    //calculate vector from light to pixel (make circular)
    vec2 lightToFrag = lightPos - vert_pos.xy;
    lightToFrag.y = lightToFrag.y / 1.6;

    //length of vector (distance)
    float vecLength = clamp(length(lightToFrag) * 4, 0, 1);

    //look up pixel in texture
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    //multiply it by colour and lighting
    if(hasTexture)
    {
        gl_FragColor = gl_Color * pixel * (clamp(ambLight + vec4(1-vecLength, 1-vecLength, 1-vecLength, 1), 0, 1));
    }
    else
    {
        gl_FragColor = gl_Color * (vec4(1-vecLength, 1-vecLength, 1-vecLength, 1) + ambLight);
    }
}

