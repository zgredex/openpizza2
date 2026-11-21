/* Sound_AllocVoice (0x5405b0, 47 bytes).  Build: /O2 /TP.
   Finds a free 0x24-byte voice slot, marks it used, and returns its payload
   pointer. */
extern "C" int __fastcall Sound_AllocVoice(int base)
{
    int i;

    for (i = 0; i < 20; i++) {
        if (*(int *)(base + 0x268 + i * 0x24) == 0) {
            *(int *)(base + 0x268 + i * 0x24) = 1;
            return base + i * 0x24 + 0x254;
        }
    }
    return 0;
}
