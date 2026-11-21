/* Tooltip_SetBackgroundImage (0x52e8b0, 48 bytes).  Build: /O2 /TP.
   Releases the old background image and loads the named replacement. */
struct UI {
    void ReleaseRefCount(int resource);
    int LoadFontByName(char *name);
};

struct Tooltip {
    void SetBackgroundImage(char *name);
};

void Tooltip::SetBackgroundImage(char *name)
{
    if (*(int *)((char *)this + 0x18) != 0)
        ((UI *)*(void **)((char *)this + 0x38))->ReleaseRefCount(
            *(int *)((char *)this + 0x18));
    if (name != 0 && *name != 0)
        *(int *)((char *)this + 0x18) =
            ((UI *)*(void **)((char *)this + 0x38))->LoadFontByName(name);
}
