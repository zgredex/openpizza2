/* BuildingMarket_BuildSortedIndex (0x4a7370). */
extern void Mem_Free(void *block);
extern void *operator_new(unsigned int size);
extern void CRT_QSort(void *base, int count, int size,
                      int (__cdecl *compare)(const void *, const void *));
extern int __cdecl BuildingMarket_Compare(const void *a, const void *b);

extern int *DAT_0057d28c;

void __cdecl BuildingMarket_BuildSortedIndex(int count)
{
    int index;

    if (DAT_0057d28c != 0) {
        Mem_Free(DAT_0057d28c);
        DAT_0057d28c = 0;
    }
    if (count > 0) {
        DAT_0057d28c = (int *)operator_new(count * 4);
        for (index = 0; index < count; index++)
            DAT_0057d28c[index] = index;
        CRT_QSort(DAT_0057d28c, count, 4, BuildingMarket_Compare);
    }
}
