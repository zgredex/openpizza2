/* ConstructionMenu_FillTimeLeft: formats the remaining construction time into
   the menu's text gadget (0x4c0390).  Build: /O2. */
struct Gadget {
    char pad[0x38];
    int field38;
};

void __cdecl Gadget_SetTextf(void *gadget, int id, char *format, int value,
                             int extra);

void ConstructionMenu_FillTimeLeft(void *gadget)
{
    struct Gadget *menu = *(struct Gadget **)0x57d708;

    Gadget_SetTextf(gadget, 0x418, (char *)0x568324, menu->field38,
                    *(int *)0x580edc);
}
