/* Game_ResizeGlobalArray3: reallocates the third global array and rebuilds
   the building rating index (0x4986f0). */
extern void *DAT_0057ca08;

void __cdecl Mem_Free(void *memory);
void * __cdecl operator_new(int size);
void __cdecl City_RebuildBuildingRatingIndex(int count);

void __cdecl Game_ResizeGlobalArray3(int count)
{
    if (DAT_0057ca08 != 0) {
        Mem_Free(DAT_0057ca08);
        DAT_0057ca08 = 0;
    }
    if (count > 0) {
        DAT_0057ca08 = operator_new(count * 4);
    }
    City_RebuildBuildingRatingIndex(count);
}
