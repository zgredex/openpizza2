/* City_RebuildProductSortIndex: fills and sorts the product index array
   (0x4c1f30). */
int __cdecl DAT_004c1f70(const void *left, const void *right);
extern int *DAT_0057d72c;
void __cdecl CRT_QSort(void *base, int count, int size,
                       int (__cdecl *compare)(const void *, const void *));

void __cdecl City_RebuildProductSortIndex(int count)
{
    int index;

    if (count > 0) {
        for (index = 0; index < count; index++)
            DAT_0057d72c[index] = index;
        CRT_QSort(DAT_0057d72c, count, 4, DAT_004c1f70);
    }
}
