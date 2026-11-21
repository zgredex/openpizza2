/* UI_DrawCenteredSelectionRect (0x4f5bb0). */
struct Gfx {
    void BlitRectList(void *rect);
};
struct UI {
    char pad00[0x24];
    int field24;
    int field28;

    void ComputeCenteredRect(int value, int *copy, int *out);
    void DrawCenteredSelectionRect(int input);
};
extern "C" char *DAT_0058072c;

void UI::DrawCenteredSelectionRect(int input)
{
    int local14;
    int rect[4];

    ComputeCenteredRect(input, &input, &local14);
    input = input - field24;
    local14 = local14 + (-0x1e - field28);
    rect[0] = input - 0x1e;
    rect[1] = local14 - 0x1e;
    rect[2] = rect[0] + 0x3c;
    rect[3] = rect[1] + 0x3c;
    ((struct Gfx *)DAT_0058072c)->BlitRectList(rect);
}
