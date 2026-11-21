/* PC2 byte-match candidate: Atexit_RegisterAnimCritSectDtor
   (0x532c00, 12 bytes). Build: /O2 /TP; entry
   _Atexit_RegisterAnimCritSectDtor. */
extern "C" void __cdecl AnimCritSectDtor(void);
extern "C" int __cdecl atexit(void (__cdecl *function)(void));

extern "C" void Atexit_RegisterAnimCritSectDtor(void)
{
    atexit(AnimCritSectDtor);
}
