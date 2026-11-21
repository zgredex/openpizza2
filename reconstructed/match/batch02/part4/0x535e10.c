/* PC2 byte-match candidate: Palette_Free (0x535e10, 14 bytes).
   Build: /O2 /TP; entry _Palette_Free. */
extern "C" void __cdecl Mem_Free(void *block);

extern "C" void __fastcall Palette_Free(void **palette)
{
    if (*palette != 0)
        Mem_Free(*palette);
}
