/* Color_Convert555To565: expands 5-bit green/red fields of 16-bit pixels
   (0x539340). */
struct ColorConverter {
    char pad[0x18];
    unsigned char enabled;
    void Convert(unsigned short *pixels, int count);
};

void ColorConverter::Convert(unsigned short *pixels, int count)
{
    if (enabled != 0 && count > 0) {
        do {
            *pixels = (*pixels & 0xffe0) << 1 | *pixels & 0x1f;
            pixels++;
        } while (--count != 0);
    }
}
