/* UI_SetButtonSpriteByName (0x531910): loads a button sprite by name through
   the window's sprite cache and notifies the button gadget.  The notify result
   is returned (both paths leave it in eax). */
struct Window {
    char pad[0x134];
    void *spriteCache;

    int LoadSpriteCached(char *name, int flags, void *out);
    int GadgetNotify(int id, int type, int code, int value, void *data);
    int SetButtonSpriteByName(int id, char *name);
};

int Window::SetButtonSpriteByName(int id, char *name)
{
    char local[0x44];

    if (((Window *)spriteCache)->LoadSpriteCached(name, 0, local) == 0)
        return 0;
    return GadgetNotify(id, 6, 0x37, 1, local);
}
