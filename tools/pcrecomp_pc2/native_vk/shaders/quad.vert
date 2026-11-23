#version 450
layout(push_constant) uniform Draw {
    vec4 dst;  // x, y, width, height (logical pixels)
    vec4 uv;   // u0,v0,u1,v1
    vec2 canvas;
    vec2 unused;
} pc;
layout(location=0) out vec2 texcoord;
void main() {
    const vec2 corners[6] = vec2[6](
        vec2(0,0), vec2(1,0), vec2(0,1),
        vec2(0,1), vec2(1,0), vec2(1,1));
    vec2 t = corners[gl_VertexIndex];
    vec2 p = pc.dst.xy + t * pc.dst.zw;
    gl_Position = vec4(p.x * 2.0 / pc.canvas.x - 1.0,
                       p.y * 2.0 / pc.canvas.y - 1.0, 0, 1);
    texcoord = mix(pc.uv.xy, pc.uv.zw, t);
}
