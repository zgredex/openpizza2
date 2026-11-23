struct Sprite {
    void GetSize(int *width, int *height);
};

struct UI {
    char pad[0x38];
    int baseX;
    int baseY;
    char pad2[0x64 - 0x40];
    int left;
    int top;
    int child2X;
    int child2Y;
    int child1X;
    int child1Y;
    int child3X;
    int child3Y;
    char pad3[0xb4 - 0x84];
    int width;
    char pad4[0xc0 - 0xb8];
    int layoutFlag;
    char pad5[0x1ec - 0xc4];
    Sprite *sprite1;
    char pad6[0x230 - 0x1f0];
    Sprite *sprite2;
    char pad7[0x274 - 0x234];
    Sprite *sprite3;
    char pad8[0x4f0 - 0x278];
    int scrollX;
    int scrollY;
    void LayoutChildElements();
};

void UI::LayoutChildElements()
{
    int width1;
    int height1;
    int width2;
    int height2;
    int x;
    int y;

    left = scrollX + baseX;
    top = scrollY + baseY;
    sprite1->GetSize(&width1, &height1);
    sprite2->GetSize(&width2, &height2);
    x = left;
    y = top;
    if (layoutFlag == 0) {
        child1X = width1 + x;
        child1Y = y;
        child2X = width + x;
        child2Y = y + height2;
        sprite3->GetSize(&width2, &height2);
        child3X = (width - width2) + left;
        child3Y = top;
        return;
    }
    child1X = x;
    child1Y = height1 + y;
    child2X = x + width2;
    child2Y = width + y;
    sprite3->GetSize(&width2, &height2);
    child3X = left;
    child3Y = (width - height2) + top;
}
