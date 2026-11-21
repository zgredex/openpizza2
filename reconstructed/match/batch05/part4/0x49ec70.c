/* Save_LoadOrInit2: sorts either the loaded or the initial product data (0x49ec70). */
extern int DAT_00568bdc;

void __cdecl Stats_SortActiveProductIndices(int *values);
void __cdecl Ranking_SortCompanyIndices(int *values);

void __cdecl Save_LoadOrInit2(int *values)
{
    if (DAT_00568bdc != 0) {
        Ranking_SortCompanyIndices(values);
        return;
    }
    Stats_SortActiveProductIndices(values);
}
