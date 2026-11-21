/* ResourceHandle_Alloc (0x402260, 47 bytes).  Build: /O2 /TP.
   Finds a free 0x24-byte resource slot, marks it used, and returns its
   payload pointer. */
extern "C" int __fastcall ResourceHandle_Alloc(int base)
{
    int i;

    for (i = 0; i < 20; i++) {
        if (*(int *)(base + 0x16f4 + i * 0x24) == 0) {
            *(int *)(base + 0x16f4 + i * 0x24) = 1;
            return base + i * 0x24 + 0x16e0;
        }
    }
    return 0;
}
