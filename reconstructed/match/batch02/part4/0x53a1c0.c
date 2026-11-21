/* PC2 byte-match candidate: Gfx_BlendTable_RegisterAtexit (0x53a1c0,
   12 bytes). Build: /O2 /TP; entry _Gfx_BlendTable_RegisterAtexit. */
extern "C" void __cdecl Gfx_BlendTableDtor(void);
extern "C" int __cdecl atexit(void (__cdecl *function)(void));

extern "C" void Gfx_BlendTable_RegisterAtexit(void)
{
    atexit(Gfx_BlendTableDtor);
}
