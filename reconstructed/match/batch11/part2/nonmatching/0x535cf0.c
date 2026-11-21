/* PaletteList_Free: frees every palette and the palette list itself
   (0x535cf0). */
struct PaletteHelper {
    void Free();
};

extern "C" void __cdecl Mem_Free(void *memory);

extern "C" void __fastcall PaletteList_Free(int *this_)
{
    if (this_[0] != 0) {
        int index;

        for (index = 0; index < this_[2]; index++) {
            void *palette = *(void **)(this_[0] + index * 4);

            if (palette != 0) {
                ((PaletteHelper *)palette)->Free();
                Mem_Free(palette);
            }
        }
        Mem_Free((void *)this_[0]);
    }
    if (this_[1] != 0)
        Mem_Free((void *)this_[1]);
}
