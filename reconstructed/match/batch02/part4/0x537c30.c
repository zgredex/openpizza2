/* PC2 byte-match candidate: Object_GetChildField14 (0x537c30, 11 bytes).
   Build: /O2 /TP; entry _Object_GetChildField14. */
extern "C" int __fastcall Object_GetChildField14(char *self)
{
    int *child = *(int **)(self + 0x14);

    if (child == 0)
        return 0;
    return *child;
}
