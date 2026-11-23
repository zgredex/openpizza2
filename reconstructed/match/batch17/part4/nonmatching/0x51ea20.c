struct Sprite {
    void GetSize(int *height, int *width);
    void GetHotspot(int *x, int *y);
};

struct Rect {
    void Union(int left, int top, int right, int bottom);
};

struct UIElement {
    void *sprite;
    char pad0[4];
    Rect *owner;
    char pad1[0xc - 0x8];
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int SetElementSprite(void *sprite, int x, int y);
};

void __fastcall CS_Enter(int section);
void __fastcall CS_Leave(int section);

int UIElement::SetElementSprite(void *sprite, int x, int y)
{
    CS_Enter(*(int *)(*(int *)((char *)this + 8) + 0x1c8));
    *(void **)this = sprite;
    int width;
    int height;
    ((Sprite *)sprite)->GetSize(&height, &width);
    if (x != -9999)
        *(int *)((char *)this + 0x1c) = x;
    if (y != -9999)
        *(int *)((char *)this + 0x20) = y;
    *(int *)((char *)this + 0x14) = 1;
    int baseX = *(int *)(*(int *)((char *)this + 8) + 0x248);
    int baseY = *(int *)(*(int *)((char *)this + 8) + 0x24c);
    int hotX;
    int hotY;
    ((Sprite *)*(void **)this)->GetHotspot(&hotX, &hotY);
    baseY = baseY + *(int *)((char *)this + 0x20);
    baseX = baseX + *(int *)((char *)this + 0x1c);
    ((Rect *)*(void **)((char *)this + 8))
        ->Union(baseX, baseY, baseX + width, baseY + height);
    if (*(int *)((char *)this + 0x18) == 0) {
        *(int *)((char *)this + 0xc) = baseX;
        *(int *)((char *)this + 0x10) = baseY;
    }
    CS_Leave(*(int *)(*(int *)((char *)this + 8) + 0x1c8));
    return 1;
}
