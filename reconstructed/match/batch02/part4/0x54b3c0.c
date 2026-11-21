/* PC2 byte-match candidate: Object_ClearField4 (0x54b3c0, 8 bytes).
   Build: /O2 /TP; entry _Object_ClearField4. */
extern "C" void __fastcall Object_ClearField4(char *self)
{
    *(int *)(self + 4) = 0;
}
