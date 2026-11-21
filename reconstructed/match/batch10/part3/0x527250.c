/* ImageCache_Clear: free every cached image entry. */
extern "C" void __fastcall Image_FreePixelData(int image);
extern "C" void __cdecl Mem_Free(void *memory);

void __fastcall ImageCache_Clear(int param_1)
{
    void *entry = *(void **)(param_1 + 0x82c4);

    while (entry != 0) {
        void *pixels;

        *(int *)(param_1 + 0x82c4) = *(int *)((char *)entry + 0x10c);
        pixels = *(void **)((char *)entry + 0x104);
        if (pixels != 0) {
            Image_FreePixelData((int)pixels);
            Mem_Free(pixels);
        }
        Mem_Free(entry);
        entry = *(void **)(param_1 + 0x82c4);
    }
}
