/* UI_DrawRectOutline: draws the four sides of a rectangle (0x521a50). */
struct DrawState {
    int mode;
    int mask;
    int color;
};

struct Color {
    int RGBTo16FromDword(unsigned int rgb);
};

struct UI {
    char pad[0x68];
    Color *color;

    void DrawLine(int x1, int y1, int x2, int y2, DrawState *state);
    void DrawRectOutline(int x1, int y1, int x2, int y2, unsigned int rgb);
};

void UI::DrawRectOutline(int x1, int y1, int x2, int y2, unsigned int rgb)
{
    DrawState state;

    state.mode = 0;
    state.color = color->RGBTo16FromDword(rgb);
    DrawLine(x1, y1, x2, y1, &state);
    DrawLine(x2, y1, x2, y2, &state);
    DrawLine(x2, y2, x1, y2, &state);
    DrawLine(x1, y2, x1, y1, &state);
}
