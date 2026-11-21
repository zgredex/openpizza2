/* PC2 byte-match candidate: Sound_SetTimeout (0x548d70, 21 bytes).
   Build: /O2.  When the object has a live sound flag, the timeout is set. */
void __fastcall Sound_SetTimeout(int sound)
{
    if (*(char *)(sound + 0xfc) != 0)
        *(int *)(sound + 0x150) = 500;
}
