/* Pak_SortEntries: sorts an array of 0x14-byte pak entries (0x402240). */
int __cdecl DAT_004021f0(const void *left, const void *right);
void __cdecl CRT_QSort(void *base, int count, int size,
                       int (__cdecl *compare)(const void *, const void *));

void __stdcall Pak_SortEntries(void *base, int count)
{
    CRT_QSort(base, count, 0x14, DAT_004021f0);
}
