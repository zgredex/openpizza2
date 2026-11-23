#version 450
layout(set = 0, binding = 0) uniform sampler2D sprite;
layout(set = 1, binding = 0) uniform sampler2D destination;
layout(set = 2, binding = 0) uniform sampler2D blend_table;
layout(location = 0) in vec2 texcoord;
layout(location = 0) out vec4 color;

int delta(int difference, int coverage) {
    return int(round(texelFetch(blend_table, ivec2(difference + 31, coverage), 0).r * 255.0)) - 128;
}

void main() {
    vec4 source = texture(sprite, texcoord);
    int coverage = int(round(source.a * 15.0));
    if (coverage == 0) discard;
    if (coverage == 15) {
        color = vec4(source.rgb, 1.0);
        return;
    }
    vec3 levels = vec3(31, 63, 31);
    ivec3 src = ivec3(round(source.rgb * levels));
    ivec3 dst = ivec3(round(texelFetch(destination, ivec2(gl_FragCoord.xy), 0).rgb * levels));
    src.g >>= 1;
    dst.g >>= 1;
    ivec3 diff = src - dst;
    ivec3 result = dst + ivec3(delta(diff.r, coverage), delta(diff.g, coverage), delta(diff.b, coverage));
    result.g <<= 1;
    color = vec4(vec3(result * 255 / ivec3(levels)) / 255.0, 1.0);
}
