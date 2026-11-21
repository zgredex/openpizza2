/* Stats_SortActiveProductIndices: qsort the active product index table (0x49eca0). */
extern int DAT_0057cc40[];
extern void __cdecl CRT_QSort(void *base, int count, int width,
                              int (__cdecl *compare)(const void *, const void *));
extern int __cdecl compare_0049ecc0(const void *left, const void *right);

void __cdecl Stats_SortActiveProductIndices(int count)
{
    if (count > 0)
        CRT_QSort(DAT_0057cc40, count, 4, compare_0049ecc0);
}
