struct UIText;
struct UICanvas { void SubtractOrigin(int *x, int *y); void ClipRect(void *rect, int flag); };
struct Font { int GetCharWidth(char character); };
struct UIText {
    char pad[8];
    UICanvas *canvas;
    char pad2[0x38 - 0x0c];
    int originX;
    char pad3[0x54 - 0x3c];
    Font *font;
    char pad4[0x6c - 0x58];
    char *text;
    char pad5[0x80 - 0x70];
    int visibleCount;
    char pad6[0x88 - 0x84];
    int limit;
    void TrimTextToWidth(int x, int y);
};
void UIText::TrimTextToWidth(int x, int y)
{
    int index;
    char character;
    canvas->SubtractOrigin(&x, &y);
    x = x - originX;
    index = 0;
    character = text[0];
    while (character != '\0') {
        x = x - font->GetCharWidth(text[index]);
        if (x < 0) break;
        index = index + 1;
        character = text[index];
    }
    visibleCount = index;
    limit = 0xfffffc19;
    canvas->ClipRect((char *)this + 0x28, 1);
}
