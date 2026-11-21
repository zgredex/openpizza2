/* SaveGame_DestroyList - 0x4cde30, 12 bytes */
extern void IDMap_DestroyAllObjects(void *map);
extern char DAT_0057df84;

void SaveGame_DestroyList(void)
{
    IDMap_DestroyAllObjects(&DAT_0057df84);
}
