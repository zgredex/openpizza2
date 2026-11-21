/* PC2 byte-match candidate: FileObject_InitBase (0x552385, 19 bytes).
   Build: /O2 /TP.  Installs the base vtable pointer and the init flag. */
extern "C" void *DAT_00577040;

void __cdecl FileObject_InitBase(int object)
{
    *(void **)(object + 0x50) = &DAT_00577040;
    *(int *)(object + 0x14) = 1;
}
