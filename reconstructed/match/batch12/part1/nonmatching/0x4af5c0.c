/* Glossary_FillPeopleNameList: fills the people-name glossary list and marks
   the current selection (0x4af5c0). */
extern unsigned DAT_0057d664;
extern unsigned DAT_00583434[];

struct Window {
    void GadgetNotify_Button_SetState(int id, unsigned state);
    void GadgetNotify_Text_SetText(int id, unsigned text);
};

void Glossary_FillPeopleNameList(Window *window, int index)
{
    unsigned *entry = &DAT_00583434[index];
    int i;

    for (i = 0; i < 13; i++) {
        window->GadgetNotify_Button_SetState(i + 0x3e9, (unsigned)(i + index) == DAT_0057d664);
        window->GadgetNotify_Text_SetText(i + 0x41f, *entry);
        entry++;
    }
}
