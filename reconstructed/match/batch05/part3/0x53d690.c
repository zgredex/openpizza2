/* Sprite_BlitOwnedRLE: blits the sprite's own RLE pixels (0x53d690). */
struct Sprite {
    char pad[0x2c];
    unsigned char *pixels;
    void BlitRLEOpaque(void *target, unsigned char *source, int a,
                       int x, int y, int b, int c);
    void BlitOwnedRLE(void *target, int x, int y);
};

void Sprite::BlitOwnedRLE(void *target, int x, int y)
{
    BlitRLEOpaque(target, pixels, 0, x, y, -2, 0);
}
