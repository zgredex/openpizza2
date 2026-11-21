/* PC2 byte-match candidate: Pak_SortEmbeddedEntries (0x53ff90, 28 bytes).
   Build: /O2 /TP.  Sorts 0x14-byte embedded pak entries. */
extern "C" void CRT_QSort(void *base, int count, int width,
                          int (__cdecl *compare)(const void *, const void *));
extern "C" int Pak_CompareEmbeddedEntries(const void *a, const void *b);

void __stdcall Pak_SortEmbeddedEntries(void *base, int count)
{
    CRT_QSort(base, count, 0x14, Pak_CompareEmbeddedEntries);
}
