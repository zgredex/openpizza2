/* PC2 byte-match candidate: Object_GetRootType (0x539f00, 24 bytes).
   Build: /O2.  Walks the parent chain while the type is 3 (root wrapper). */
int __fastcall Object_GetRootType(int object)
{
    int type = *(int *)(object + 0x4c);

    while (type == 3) {
        object = *(int *)(object + 0x54);
        type = *(int *)(object + 0x4c);
    }
    return *(int *)(object + 0x4c);
}
