/* PlayerRecordPanel_SortIndices: fills and sorts the player record index
   array (0x4c1ef0). */
int __cdecl DAT_004c1a60(const void *left, const void *right);
extern int *DAT_0057d72c;
void __cdecl CRT_QSort(void *base, int count, int size,
                       int (__cdecl *compare)(const void *, const void *));

void __cdecl PlayerRecordPanel_SortIndices(int count)
{
    int index;

    if (count > 0) {
        for (index = 0; index < count; index++)
            DAT_0057d72c[index] = index;
        CRT_QSort(DAT_0057d72c, count, 4, DAT_004c1a60);
    }
}
