/* Font_GetCharWidth: returns the pixel width of a printable character
   (0x535650). */
struct Font {
    char pad[0x1c0];
    unsigned char widths[0x100];
    char pad2[0x1a0];
    int *metrics;
    int GetCharWidth(unsigned char ch);
};

int Font::GetCharWidth(unsigned char ch)
{
    int index = (ch & 0xff) - 0x20;

    if (index < 0 || index >= 0xe0)
        return 0;
    if (*(int *)((char *)this + index * 4 + 0x460) == 0)
        return 0;
    return *(unsigned char *)((char *)this + 0x1c0 + index);
}
