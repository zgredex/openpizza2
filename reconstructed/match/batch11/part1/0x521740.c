/* UI_DrawChildSprite: builds a three-entry color descriptor and forwards the
   draw call (0x521740). */
struct SpriteOwner {
    char pad[0x68];
    void *sprite;
};

struct ColorHelper {
    int RGBTo16FromDword(unsigned int color);
};

struct UIHelper {
    void DrawLine(void *p1, int p2, void *p3, int p4, int *colors);
};

struct ChildSprite {
    void DrawChildSprite(void *p1, int p2, void *p3, int p4, unsigned int color);
};

void ChildSprite::DrawChildSprite(void *p1, int p2, void *p3, int p4,
                                  unsigned int color)
{
    int local[3];

    local[0] = 0;
    local[2] = ((ColorHelper *)((SpriteOwner *)this)->sprite)
                   ->RGBTo16FromDword(color);
    local[1] = 0;
    ((UIHelper *)this)->DrawLine(p1, p2, p3, p4, local);
}
