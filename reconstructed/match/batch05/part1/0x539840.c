/* Color_RGBTo16FromDword: splits a packed dword into colour components and
   converts (0x539840). The callee's declaration uses 32-bit parameters, so
   each component is zero-extended exactly as in the original. */
struct Color {
    unsigned short RGBTo16(unsigned int red, unsigned int green,
                           unsigned int blue);
    void RGBTo16FromDword(unsigned int color);
};

void Color::RGBTo16FromDword(unsigned int color)
{
    RGBTo16(color & 0xff, (color >> 8) & 0xff, (color >> 16) & 0xff);
}
