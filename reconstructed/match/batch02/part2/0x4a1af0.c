/* SaveGameList_Destroy - 0x4a1af0, 12 bytes */
extern void IDMap_DestroyAllObjects(void *map);
extern char DAT_0057cfc8;

void SaveGameList_Destroy(void)
{
    IDMap_DestroyAllObjects(&DAT_0057cfc8);
}
