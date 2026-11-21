/* Color_RGBTo16: converts an RGB colour to the surface's 16-bit format
   (0x5397e0). */
struct ColorSpace {
    char pad[0x18];
    char format;

    unsigned RGBTo16(unsigned char red, unsigned char green, unsigned blue);
};

unsigned ColorSpace::RGBTo16(unsigned char red, unsigned char green,
                             unsigned blue)
{
    if (format != 0) {
        return ((red & 0xf8) << 5 | green & 0xf8) << 3 |
               (unsigned char)(blue & 0xff) >> 3;
    }
    return ((red & 0xf8) << 5 | green & 0xf8) << 2 |
           (unsigned char)(blue & 0xff) >> 3;
}
