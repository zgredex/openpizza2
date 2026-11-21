/* PC2 byte-match candidate: Buffer_ReleaseField8 (0x541f00, 15 bytes).
   Build: /O2 /TP; entry _Buffer_ReleaseField8. */
extern "C" void __cdecl Mem_Free(void *block);

extern "C" void __fastcall Buffer_ReleaseField8(char *buffer)
{
    void *block = *(void **)(buffer + 8);

    if (block != 0)
        Mem_Free(block);
}
