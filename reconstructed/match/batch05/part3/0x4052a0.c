/* Screen_CloseSubStartMenu: destroys the active sub start menu (0x4052a0). */
struct Window {
    void DestroyChild(void *child);
};

extern Window *DAT_0057c5e0;
extern void *DAT_0057c5f0;

void __cdecl Screen_CloseSubStartMenu(void)
{
    if (DAT_0057c5f0 != 0)
        DAT_0057c5e0->DestroyChild(DAT_0057c5f0);
    DAT_0057c5f0 = 0;
}
