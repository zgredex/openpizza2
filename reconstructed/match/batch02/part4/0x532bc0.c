/* PC2 byte-match candidate: Atexit_RegisterAnimSwapCritSectDtor
   (0x532bc0, 12 bytes). Build: /O2 /TP; entry
   _Atexit_RegisterAnimSwapCritSectDtor. */
extern "C" void __cdecl AnimSwapCritSectDtor(void);
extern "C" int __cdecl atexit(void (__cdecl *function)(void));

extern "C" void Atexit_RegisterAnimSwapCritSectDtor(void)
{
    atexit(AnimSwapCritSectDtor);
}
