// Map_UpdateVisibilityFlags: draws one object's sprites with palette expansion.

extern char DAT_00585518[];
extern char DAT_0057c670[];

struct Sprite {
    void *GetPalette();
};

struct Palette {
    void Expand(void *sprite, unsigned int start, int count);
};

struct UI {
    void DrawObjectSprite(void *param, void *sprite);
};

struct Map {
    void BlitAlignedObjectSprite(void *param, void *sprite);
};

struct MapView {
    void UpdateVisibilityFlags(void *param);
};

void MapView::UpdateVisibilityFlags(void *param)
{
    char *object = *(char **)((char *)param + 8);
    unsigned int shape = *(unsigned int *)object;
    int field10 = *(int *)(object + 0x10);

    if (field10 >= 0x868 && field10 <= 0x87d)
        *(char *)(object + 0x2e) = 0;
    if (*(int *)DAT_00585518 <= (int)((shape & 7) + 0xa0))
        return;
    if (*(unsigned char *)(object + 0x2e) == 1)
        return;
    if (field10 >= 0x6e8 && field10 <= 0x6f3 &&
        *(int *)DAT_00585518 > (int)((shape & 7) + 0x78))
        return;
    if (field10 >= 0x6f4 && field10 <= 0x6fb &&
        *(int *)DAT_00585518 > (int)((shape & 7) + 0x8c))
        return;
    {
        char *table = *(char **)((char *)this + 4);
        char *sprite = *(char **)(table + field10 * 0x48 + 0x5c);
        if (sprite != 0) {
            unsigned int pal = *(unsigned char *)(object + 0x2d);
            if (pal != 0) {
                void *palette = ((Sprite *)sprite)->GetPalette();
                if (palette != 0)
                    ((Palette *)DAT_0057c670)->Expand(
                        palette,
                        *(unsigned char *)(*(int *)((char *)this + 8) + 0x18),
                        pal - 1);
            }
            ((UI *)this)->DrawObjectSprite(param, sprite);
        }
        sprite = *(char **)(table + field10 * 0x48 + 0x64);
        if (sprite != 0)
            ((Map *)this)->BlitAlignedObjectSprite(param, sprite);
    }
}
