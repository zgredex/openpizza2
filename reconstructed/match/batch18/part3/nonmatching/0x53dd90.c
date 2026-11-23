/* Sprite_FillColor8: fills a rotated 8-bit sprite with its colour or checker
   pattern (0x53dd90). */
struct Sprite {
    char pad0[4];
    unsigned char flags;
    unsigned char type;
    short field6;
    short field8;
    char pad2[0x12];
    unsigned char color;
    char pad3[0x13];
    unsigned char *pixels;
    char pad4[2];
    unsigned char field36;
    unsigned char field37;
    void Rotate(int angle);
    int FillColor8();
};

int Sprite::FillColor8()
{
    int rows;
    int width;
    unsigned char color;
    unsigned char *dest;
    unsigned int y;
    unsigned int x;
    unsigned char *p;
    unsigned int count;

    if ((flags & 1) != 0 || type != 8) {
        return 0;
    }
    if (field36 == '\xff') {
        Rotate(0);
    }
    if (field36 == '\xff') {
        return 0;
    }
    dest = pixels;
    if (field37 != 0) {
        rows = field6;
        width = field8;
    } else {
        rows = field8;
        width = field6;
    }
    color = this->color;
    y = 0;
    if (0 < rows) {
        do {
            if ((flags & 0x10) == 0) {
                for (x = y & 1; (int)x < width; x = x + 2) {
                    *(dest + x) = color;
                }
                dest = dest + width;
            } else {
                x = y & 1;
                if ((int)x < width) {
                    p = dest + x * 2;
                    count = (width - x) + 1 >> 1;
                    do {
                        *p = 0;
                        p[1] = 1;
                        p = p + 4;
                        count = count - 1;
                    } while (count != 0);
                }
                dest = dest + width * 2;
            }
            y = y + 1;
        } while ((int)y < rows);
    }
    return 1;
}
