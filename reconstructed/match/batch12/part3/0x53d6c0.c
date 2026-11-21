/* Sprite_FillTransparentColor (0x53d6c0). */

extern void *DAT_0057c5c8;

struct Sprite {
    void FillTransparentColor(int color);
    void RealizeLazy();
    void SetColorKey(int color);
};

void Mem_FillWord(void *buffer, short value, int count);

void Sprite::FillTransparentColor(int color)
{
    if (*(char *)((char *)this + 0x39) == 0) {
        RealizeLazy();
    }
    if (color == -1) {
        if (*(char *)((char *)this + 4) != 0) {
            color = *(int *)((char *)this + 0x1c);
        } else {
            color = (*(char *)((char *)DAT_0057c5c8 + 0x18) != 0)
                    ? 0xfffffc00 : 0;
            color += 0x7e0;
            SetColorKey(color);
        }
    }
    Mem_FillWord(*(void **)((char *)this + 0x2c), (short)color,
                 *(int *)((char *)this + 0x18) >> 1);
}
