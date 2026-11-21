/* UI_AlignSpriteToRect: centers a sprite inside a rectangle and computes its
   output position (0x4ed780). */
struct Sprite {
    void GetRenderSize(int *width, int *height);
};

struct UI {
    char pad[0xc];
    int width;
    int spacing;
    char pad1[0x10];
    int offsetX;
    int offsetY;

    void AlignSpriteToRect(int *position, void *sprite, int *outX, int *outY);
};

void UI::AlignSpriteToRect(int *position, void *sprite, int *outX, int *outY)
{
    int spriteWidth;

    ((Sprite *)sprite)->GetRenderSize(&spriteWidth, (int *)&sprite);
    *outX = ((width >> 1) - (spriteWidth >> 1) - offsetX) + position[0];
    {
        int y = position[1] - offsetY;

        *outY = y;
        if (width == 0x10) {
            int height = (int)sprite;
            int value = y - height;
            *outY = value;
            *outY = value + spacing * 3;
            return;
        }
        if (spriteWidth > width) {
            int height = (int)sprite;
            int value = y - height;
            *outY = value;
            *outY = value + spacing * 3;
        }
    }
}
