/* Font_MeasureText: measures a string with the font's glyph width table
   (0x5355f0). */
struct Font {
    char pad[0x1c0];
    unsigned char widths[0x2a0];

    int MeasureText(char *text);
};

int Font::MeasureText(char *text)
{
    int width = 0;
    int index = 0;
    char c = *text;

    while (c != 0) {
        unsigned char glyph;

        c = *text;
        text++;
        index = (unsigned char)(c - 0x20);
        if (index >= 0 && index < 0xe0 &&
            *(int *)((char *)this + index * 4 + 0x460) != 0) {
            glyph = *(unsigned char *)((char *)this + 0x1c0 + index);
        } else {
            glyph = *(unsigned char *)((char *)this + 0x1c0);
        }
        width += glyph;
        c = *text;
    }
    return width;
}
