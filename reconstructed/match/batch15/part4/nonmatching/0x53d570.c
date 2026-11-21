/* Non-matching candidate.
   First difference: offset 0x15, 83 bytes differ.
   original leaves the pixels==0 branch out of line after both other branches; candidate orders the blocks differently.
   Kept for evidence; not part of the strict match set. */
struct Sprite {
    char pad0[6];
    short field6;
    short field8;
    char pad1[0x28 - 0xa];
    int field28;
    void *field2c;
    void *field30;
    char pad2[0x37 - 0x34];
    char field37;
    char pad3[0x39 - 0x38];
    char field39;
    void RealizeLazy();
    void BlitAlphaRLEAlt(int param_1, void *pixels, int a, unsigned *param_2,
                         int param_3, unsigned char *x, int y);
    void Draw(int param_1, unsigned *param_2, int param_3);
};

void Sprite::Draw(int param_1, unsigned *param_2, int param_3)
{
    if (field39 == 0)
        RealizeLazy();
    void *pixels = *(void **)((char *)this + 0x30);
    if (pixels != 0) {
        if (field37 != 0) {
            BlitAlphaRLEAlt(param_1, pixels, field28, param_2, param_3,
                            (unsigned char *)(int)field8, (int)field6);
        } else {
            BlitAlphaRLEAlt(param_1, pixels, field28, param_2, param_3,
                            (unsigned char *)0xffffffff, -1);
        }
    } else {
        BlitAlphaRLEAlt(param_1, *(void **)((char *)this + 0x2c), field28,
                        param_2, param_3, (unsigned char *)0xffffffff, -1);
    }
}
