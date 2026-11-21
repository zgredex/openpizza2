/* UI_FindFontByName: finds a cached font record by case-insensitive name
   (0x526f60). */
extern "C" int FUN_005570c0(unsigned char *left, unsigned char *right);

struct UI {
    char pad[0x82c4];
    unsigned char *fonts;
    unsigned char *FindFontByName(unsigned char *name);
};

unsigned char *UI::FindFontByName(unsigned char *name)
{
    unsigned char *font = *(unsigned char **)((char *)this + 0x82c4);

    while (font != 0) {
        if (FUN_005570c0(font, name) == 0)
            return font;
        font = *(unsigned char **)(font + 0x10c);
    }
    return 0;
}
