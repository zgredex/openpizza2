/* UI_AlignSpriteToObject: computes a linked object's extent and aligns the
   sprite rectangle to it (0x4f5730). */
struct Game {
    void *GetLinkedObjectExtent(int *rect, unsigned int *x, unsigned int *y);
};

struct UI {
    void AlignSpriteToRect(int *rect, void *extent, int *a, int *b);
    void AlignSpriteToObject(int *rect, int *a, int *b, unsigned int *x,
                             unsigned int *y);
};

void UI::AlignSpriteToObject(int *rect, int *a, int *b, unsigned int *x,
                             unsigned int *y)
{
    void *extent = ((Game *)this)->GetLinkedObjectExtent(rect, x, y);

    AlignSpriteToRect(rect, extent, a, b);
}
