/* SaveGame_LookupSavedId: finds a saved id in the linear map at offset 0xfac (0x4d75b0). */
struct Map {
    void *LookupLinear(int key);
};

struct SaveGame {
    char pad[0xfac];
    Map savedIds;
    void LookupSavedId(int id);
};

void SaveGame::LookupSavedId(int id)
{
    savedIds.LookupLinear(id);
}
