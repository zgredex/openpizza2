/* Game_ResizeGlobalArray: reallocates the global index array and re-sorts its
   records (0x49c110). */
extern void *DAT_0057ca94;
extern char DAT_005689f0;

void Mem_Free(void *block);
extern "C" void *operator_new(unsigned int size);
void Stats_SortCompanyIndexArray(int count);
void Ranking_SortRecordIndices(int count);

void Game_ResizeGlobalArray(int count)
{
    if (DAT_0057ca94 != 0) {
        Mem_Free(DAT_0057ca94);
        DAT_0057ca94 = 0;
    }
    if (count > 0) {
        DAT_0057ca94 = operator_new(count * 4);
    }
    if (DAT_005689f0 != 0) {
        Ranking_SortRecordIndices(count);
    } else {
        Stats_SortCompanyIndexArray(count);
    }
}
