struct Window {
    void GadgetNotify_Text_SetText(int id, char *text);
    void GadgetNotify_Text_SetTextColor(int id, int color);
};

extern int DAT_0057bcd8;
extern int DAT_0057bd9c;
extern char DAT_005686f8[];
extern char DAT_005686f4[];

extern "C" void String_Format(char *buffer, const char *format, ...);

extern "C" void FreePlaySetup_FillCityTable(void *window)
{
    char buffer[32];
    String_Format(buffer, DAT_005686f8, DAT_0057bcd8);
    ((Window *)window)->GadgetNotify_Text_SetText(0x453, buffer);
    int id = 0x45a;
    int *entry = &DAT_0057bd9c;
    do {
        String_Format(buffer, DAT_005686f8, entry[-1]);
        ((Window *)window)->GadgetNotify_Text_SetText(id + 1, buffer);
        int value = *entry;
        String_Format(buffer, DAT_005686f4, value);
        int color;
        if (value == 0)
            color = 0;
        else if (value < 0)
            color = 0xff;
        else
            color = 0xa000;
        ((Window *)window)->GadgetNotify_Text_SetTextColor(id, color);
        ((Window *)window)->GadgetNotify_Text_SetText(id, buffer);
        entry += 0x30;
        id += 8;
    } while ((int)entry < 0x57c15c);
}
