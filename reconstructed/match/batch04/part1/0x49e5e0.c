/* Stats_SortCategoryIndexArray: sorts the shared category index array
   (0x49e5e0). */
int __cdecl DAT_0049e600(const void *left, const void *right);
extern int DAT_0057cadc[];
void __cdecl CRT_QSort(void *base, int count, int size,
                       int (__cdecl *compare)(const void *, const void *));

void __cdecl Stats_SortCategoryIndexArray(int count)
{
    if (count > 0)
        CRT_QSort(DAT_0057cadc, count, 4, DAT_0049e600);
}
