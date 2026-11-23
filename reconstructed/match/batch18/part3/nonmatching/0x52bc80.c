/* UI_Text_Construct: constructs a UI text element (0x52bc80). */
extern "C" void *__cdecl LoadFontByName(void *owner, char *name);

struct Font {
    void SetMarkupText(char *text);
    int Measure();
};

struct UI_Child {
    void Construct(int a, int b, int c, int d);
};

struct UI_TextElement : UI_Child {
    char pad[0x40];
    char offset14[0x14];
    int field14;
    char offset18[0x28];
    int field40;
    Font *font;
    int field54;
    char pad2[0x14];
    int field58;
    int field5c;
    int field60;
    unsigned short field64;
    unsigned short field66;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field88;
    char rest[0x4c];
    int *Construct(int a, int b, int c, char *fontName, char *text, void *owner, int *error);
};

int *UI_TextElement::Construct(int a, int b, int c, char *fontName, char *text,
                               void *owner, int *error)
{
    UI_Child::Construct(a, b, c, 3);
    *(void **)this = (void *)0x55c7cc;
    *error = 0;
    field40 = 3;
    field74 = 0;
    field78 = 0;
    field60 = 0;
    field88 = 0;
    font = (Font *)LoadFontByName(*(void **)((char *)owner + 0x134), fontName);
    field54 = (int)font;
    if (field54 == 0) {
        *error = 1;
    } else {
        field88 = 0;
        field58 = 0xffffff;
        field64 = 0;
        field66 = 0xffff;
        field6c = 0;
        field70 = 3;
        font->SetMarkupText(text);
        font->Measure();
        field14 = 0;
    }
    return (int *)this;
}
