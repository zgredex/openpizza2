/* UI_SetOnlineHelpText: sets gadget 0x429's text (0x4c70f0). */
struct Window {
    void GadgetNotify_Text_SetText(int gadget, int text);
};

void __cdecl UI_SetOnlineHelpText(void *window, int text)
{
    ((Window *)window)->GadgetNotify_Text_SetText(0x429, text);
}
