/* UI_DestroyWindowAt: clears a window slot and destroys the old window
   (0x482860). */
struct Window {
    void DestroyChild(void *child);
};

extern Window *DAT_0057c5e0;

void __stdcall UI_DestroyWindowAt(void **slot)
{
    void *child = *slot;

    *slot = 0;
    DAT_0057c5e0->DestroyChild(child);
}
