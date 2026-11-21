/* Window_Destroy: releases the window's owned buffers and resets its vtable
   (0x537350). */
struct Palette {
    void Free();
};

void __cdecl Mem_Free(void *block);

void __fastcall Window_Destroy(void **window)
{
    Palette *palette;

    window[0] = (void *)0x55c814;
    if (window[6] != 0)
        Mem_Free(window[6]);
    palette = (Palette *)window[5];
    if (palette != 0) {
        palette->Free();
        Mem_Free(palette);
    }
}
