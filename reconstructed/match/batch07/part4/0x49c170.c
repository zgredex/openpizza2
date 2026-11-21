/* Ranking_SortRecordIndices: fills and sorts the ranking record index array
   (0x49c170). */
int __cdecl DAT_0049c1b0(const void *left, const void *right);
extern int *DAT_0057ca94;
void __cdecl CRT_QSort(void *base, int count, int size,
                       int (__cdecl *compare)(const void *, const void *));

void __cdecl Ranking_SortRecordIndices(int count)
{
    int index;

    if (count > 0) {
        for (index = 0; index < count; index++)
            DAT_0057ca94[index] = index;
        CRT_QSort(DAT_0057ca94, count, 4, DAT_0049c1b0);
    }
}
