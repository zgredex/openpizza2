/* Game_ResizeGlobalArray2: reallocates the second global index array and
   re-sorts its records (0x4c1e90). */
extern void *DAT_0057d72c;
extern int DAT_0057d728;

void Mem_Free(void *block);
extern "C" void *operator_new(unsigned int size);
void PlayerRecordPanel_SortIndices(int count);
void City_RebuildProductSortIndex(int count);

void Game_ResizeGlobalArray2(int count)
{
    if (DAT_0057d72c != 0) {
        Mem_Free(DAT_0057d72c);
        DAT_0057d72c = 0;
    }
    if (count > 0) {
        DAT_0057d72c = operator_new(count * 4);
    }
    if (DAT_0057d728 == 0) {
        PlayerRecordPanel_SortIndices(count);
    } else {
        City_RebuildProductSortIndex(count);
    }
}
