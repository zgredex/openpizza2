/* FreePlaySetup_SetDifficultyText: shows the localized difficulty name (0x4c7090). */
extern int DAT_005840a8[];

struct Window {
    void GadgetNotify_Text_SetText(int gadget, int text);
};

void __cdecl FreePlaySetup_SetDifficultyText(void *window, int difficulty)
{
    ((Window *)window)->GadgetNotify_Text_SetText(0x408, DAT_005840a8[difficulty]);
}
