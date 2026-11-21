/* Save_LoadOrInit: sorts either the loaded or the initial category data (0x49e5b0). */
extern int DAT_00568b48;

void __cdecl Stats_SortCategoryIndexArray(int *values);
void __cdecl CompanyBuildingList_SortIndices(int *values);

void __cdecl Save_LoadOrInit(int *values)
{
    if (DAT_00568b48 != 0) {
        CompanyBuildingList_SortIndices(values);
        return;
    }
    Stats_SortCategoryIndexArray(values);
}
