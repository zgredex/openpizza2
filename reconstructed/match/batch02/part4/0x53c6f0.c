/* PC2 byte-match candidate: Sprite_CriticalSection_RegisterAtexit
   (0x53c6f0, 12 bytes). Build: /O2 /TP; entry
   _Sprite_CriticalSection_RegisterAtexit. */
extern "C" void __cdecl SpriteCriticalSectionDtor(void);
extern "C" int __cdecl atexit(void (__cdecl *function)(void));

extern "C" void Sprite_CriticalSection_RegisterAtexit(void)
{
    atexit(SpriteCriticalSectionDtor);
}
