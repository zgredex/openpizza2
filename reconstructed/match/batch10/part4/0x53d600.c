/* Sprite_BlitWithDefaultAlpha (0x53d600): realizes a lazily loaded sprite and
   blits it with the default alpha when none was supplied. */
extern "C" {
extern int DAT_00585518;
}

struct Sprite {
    char pad[0x28];
    void *field28;
    void *field2c;
    char pad2[0x39 - 0x30];
    char field39;

    int RealizeLazy();
    int BlitAlphaRLE(int x, int y, void *src, void *dst, int width,
                     int height, int alpha);
    int BlitWithDefaultAlpha(int x, int y, int width, int flags, int alpha);
};

int Sprite::BlitWithDefaultAlpha(int x, int y, int width, int flags, int alpha)
{
    if (field39 == 0)
        RealizeLazy();
    if (alpha == -1)
        alpha = DAT_00585518;
    return BlitAlphaRLE(x, y, field2c, field28, width, flags, alpha);
}
