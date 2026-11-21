/* Object_ClearFieldsA: clears seven dword fields (0x521180). */
void __fastcall Object_ClearFieldsA(char *object)
{
    *(int *)(object + 0x54) = 0;
    *(int *)(object + 0x58) = 0;
    *(int *)(object + 0x70) = 0;
    *(int *)(object + 0x9c) = 0;
    *(int *)(object + 0x78) = 0;
    *(int *)(object + 0x6c) = 0;
    *(int *)(object + 0x64) = 0;
}
