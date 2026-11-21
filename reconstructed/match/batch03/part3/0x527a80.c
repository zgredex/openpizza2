struct Renderer {
    void ApplySpriteTint(unsigned short *pixels, int mode);
};

struct UI {
    char pad0[0x8310];
    Renderer *renderer;

    void ApplyChildSpriteTint(unsigned short *pixels, int mode);
};

void UI::ApplyChildSpriteTint(unsigned short *pixels, int mode)
{
    renderer->ApplySpriteTint(pixels, mode);
}
