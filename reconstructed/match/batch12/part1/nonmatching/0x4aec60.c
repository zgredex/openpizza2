/* Glossary_FillCityBuildingList: fills the city building glossary list and
   marks the current selection (0x4aec60). */
extern unsigned DAT_0057d64c;
extern unsigned DAT_0058404c[];

struct Window {
    void GadgetNotify_Button_SetState(int id, unsigned state);
    void GadgetNotify_Text_SetText(int id, unsigned text);
};

void Glossary_FillCityBuildingList(Window *window, int index)
{
    unsigned *entry = &DAT_0058404c[index];
    int i;

    for (i = 1001; i - 1001 < 13; i++) {
        window->GadgetNotify_Button_SetState(
            i, (unsigned)(i - 1001 + index) == DAT_0057d64c);
        window->GadgetNotify_Text_SetText(i + 0x36, *entry);
        entry++;
    }
}
