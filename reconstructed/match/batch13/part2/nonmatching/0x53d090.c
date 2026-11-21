/* Sprite_GetSize (0x53d090). */
struct Sprite {
    char pad0[5];
    unsigned char flags;    /* 0x05 */
    short width;            /* 0x06 */
    short height;           /* 0x08 */
    char pad1[0x30 - 0x0a];
    int field30;            /* 0x30 */
    char pad2[3];
    char field37;           /* 0x37 */

    void GetSize(int *width, int *height);
};

void Sprite::GetSize(int *widthOut, int *heightOut)
{
    if (field30 != 0) {
        char status = field37;
        unsigned char f = flags;

        if (status != 0) {
            *heightOut = f >= 0xf ? width >> 1 : width;
            *widthOut = height;
        } else {
            int value = width;

            if (f >= 0xf)
                value = value >> 1;
            *widthOut = value;
            *heightOut = height;
        }
    } else {
        *widthOut = flags >= 0xf ? width >> 1 : width;
        *heightOut = height;
    }
}
