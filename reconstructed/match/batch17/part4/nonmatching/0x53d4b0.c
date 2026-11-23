struct Color {
    void Convert555To565(unsigned short *pixels, int count);
};

struct Sprite {
    char pad0[4];
    unsigned char flags;
    unsigned char type;
    char pad1[0x18 - 0x6];
    int width;
    unsigned int transparent;
    char pad2[0x2c - 0x20];
    unsigned short *pixels;
    void ConvertRGB555to565(void *target);
};

void Sprite::ConvertRGB555to565(void *target)
{
    if (*(char *)((char *)this + 5) != 0xf &&
        *(char *)((char *)this + 5) != 0x10)
        return;
    unsigned short *pixels = *(unsigned short **)((char *)this + 0x2c);
    if ((*(unsigned char *)((char *)this + 4) & 1) != 0) {
        if (*(char *)((char *)target + 0x18) != 1)
            return;
        if ((*(unsigned char *)((char *)this + 4) & 0x10) != 0)
            return;
        int i = 0;
        if (0 < (int)(*(unsigned int *)((char *)this + 0x18) & 0xfffffffe)) {
            do {
                unsigned short value = *pixels;
                if ((unsigned int)value == *(unsigned int *)((char *)this + 0x1c)) {
                    i++;
                    *pixels = (value & 0xffe0) << 1 | value & 0x1f;
                    pixels++;
                } else {
                    *pixels = (value & 0xffe0) << 1 | value & 0x1f;
                }
                i++;
                pixels++;
            } while (i < *(int *)((char *)this + 0x18) >> 1);
        }
    } else {
        ((Color *)target)->Convert555To565(pixels, *(int *)((char *)this + 0x18) >> 1);
        if (*(char *)((char *)target + 0x18) == 0)
            return;
    }
    *(unsigned int *)((char *)this + 0x1c) =
        (*(unsigned int *)((char *)this + 0x1c) & 0x7fe0) << 1 |
        *(unsigned int *)((char *)this + 0x1c) & 0x1f;
}
