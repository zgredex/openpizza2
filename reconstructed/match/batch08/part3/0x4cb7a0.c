/* FreePlaySetup_FillStartCapitalText: builds the starting-capital string
   (0x4cb7a0). */
extern int DAT_0057bb28;
extern int DAT_005823cc;

struct Window {
    void GadgetNotify_Text_SetText(int id, char *text);
};

extern "C" int __cdecl String_Format(char *buffer, const char *format,
                                     int value, int extra);

void __cdecl FreePlaySetup_FillStartCapitalText(Window *window)
{
    char text[32];

    String_Format(text, (const char *)0x568324, DAT_0057bb28, DAT_005823cc);
    window->GadgetNotify_Text_SetText(0x438, text);
}
