/* PC2 byte-match candidate: MapView_GetRotation (0x527ab0, 17 bytes).
   Build: /O2 /TP; entry _MapView_GetRotation. */
extern "C" int __fastcall MapView_GetRotation(char *self)
{
    int *view = *(int **)(self + 0x8310);

    return view ? *(int *)((char *)view + 0x24) : 0;
}
