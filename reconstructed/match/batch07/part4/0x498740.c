/* City_RebuildBuildingRatingIndex: fills and sorts the building rating index
   array (0x498740). */
int __cdecl DAT_00498370(const void *left, const void *right);
extern int *DAT_0057ca08;
void __cdecl CRT_QSort(void *base, int count, int size,
                       int (__cdecl *compare)(const void *, const void *));

void __cdecl City_RebuildBuildingRatingIndex(int count)
{
    int index;

    if (count > 0) {
        for (index = 0; index < count; index++)
            DAT_0057ca08[index] = index;
        CRT_QSort(DAT_0057ca08, count, 4, DAT_00498370);
    }
}
