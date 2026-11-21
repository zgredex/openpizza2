/* SaveGameMenu_DestroyList: destroys the saved-game object list (0x4a0a60). */
extern char DAT_0057cdb4;
void __cdecl IDMap_DestroyAllObjects(void *map);

void SaveGameMenu_DestroyList(void)
{
    IDMap_DestroyAllObjects(&DAT_0057cdb4);
}
