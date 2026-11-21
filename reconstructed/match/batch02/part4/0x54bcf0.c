/* PC2 byte-match candidate: Window_ClearState (0x54bcf0, 12 bytes).
   Build: /O2 /TP; entry _Window_ClearState. */
extern "C" void __fastcall Window_ClearState(char *window)
{
    *(int *)(window + 0x1a8) = 0;
    *(int *)(window + 4) = 0;
}
