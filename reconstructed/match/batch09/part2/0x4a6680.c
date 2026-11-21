/* UI_PrintSignedValue: prints an integer with a sign-dependent colour
   (0x4a6680). */
struct Window_GadgetNotify_Text {
    void SetTextColor(void *target, int color);
};

extern void __cdecl Gadget_SetTextf(void *gadget, void *target, char *format,
                                    int value);

void __cdecl UI_PrintSignedValue(void *gadget, void *target, int value)
{
    if (value > 0)
        ((struct Window_GadgetNotify_Text *)gadget)->SetTextColor(target, 0xa000);
    else if (value == 0)
        ((struct Window_GadgetNotify_Text *)gadget)->SetTextColor(target, 0);
    else
        ((struct Window_GadgetNotify_Text *)gadget)->SetTextColor(target, 0xff);
    Gadget_SetTextf(gadget, target, (char *)0x5686f4, value);
}
