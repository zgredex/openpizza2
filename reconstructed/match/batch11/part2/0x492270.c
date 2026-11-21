/* UI_FillObjectWithPaletteColor: fills a window object with one of the
   palette colors (0x492270). */
struct UIHelper {
    void *GetWindowObject(int index);
    void RealizeSprite();
    void GetChildSize(int *width, int *height);
    void ClipChildRect();
};

struct SpriteHelper {
    void FillRectColor(int x, int y, int width, int height, unsigned int color);
};

extern "C" void __cdecl UI_FillObjectWithPaletteColor(void *window, int index,
                                                       int color)
{
    void *object = ((UIHelper *)window)->GetWindowObject(index);
    int width;
    int height;

    ((UIHelper *)object)->RealizeSprite();
    ((UIHelper *)object)->GetChildSize(&width, &height);
    ((SpriteHelper *)object)
        ->FillRectColor(0, 0, width, height,
                        *(unsigned int *)(0x56869c + color * 4));
    ((UIHelper *)object)->ClipChildRect();
}
