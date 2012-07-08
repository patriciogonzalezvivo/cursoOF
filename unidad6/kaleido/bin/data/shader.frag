uniform sampler2DRect text;
uniform vec2 size;
uniform float rotate;

void main(){

    vec2 st = gl_TexCoord[0].xy;
    st.x -= size.x*0.5; 
    st.y -= size.y*0.5; 
    vec2 uv;
    
    float angle = atan(st.y,st.x);
    float radio = sqrt(dot(st,st));// length(st);
    
    uv.x = cos( angle - rotate) * radio + size.x*0.5;
    uv.y = sin( angle - rotate) * radio + size.y*0.5;
    
    vec3 color = texture2DRect(text, uv).rgb;
    gl_FragColor = vec4(color, 1.0);
}
