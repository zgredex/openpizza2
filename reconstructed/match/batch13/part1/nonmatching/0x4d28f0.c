/* Game_AddObjectToList (0x4d28f0). */
struct Map {
    int LookupLinear(int key);
    void Add(int key);
    void SetCellObjectFrame(int x, char frame);
};
struct IDMap {
    char pad[0x14];
    void *Lookup(int key, int *out);
};
struct MapView {
    char pad[0xfa8];
    Map *map;
};
struct GameObject {
    char pad0[0x24];
    int x;                  /* 0x24 */
    int y;                  /* 0x28 */
    char pad1[0x138];       /* to 0x164 */
    int key;                /* 0x164 */

    void SetField168(void *game);
};
struct Game {
    char pad0[0x24];
    int x;                  /* 0x24 */
    int y;                  /* 0x28 */
    char pad0b[0x4c];       /* to 0x78 */
    Map map;                /* 0x78 */
    char pad1[0x10];        /* to 0x8c */
    int mode;               /* 0x8c */

    void AddObjectToList(GameObject *object);
};
extern Game *DAT_0057c670;

void Game::AddObjectToList(GameObject *object)
{
    int key = object->key;

    if (map.LookupLinear(key) == -1) {
        map.Add(key);
        object->SetField168(this);
        if (mode == 1) {
            void *record = ((IDMap *)((char *)DAT_0057c670 + 4))->Lookup(y, 0);
            int cellX = x;
            Map *cellMap = *(Map **)((char *)record + 0xfa8);

            cellMap->SetCellObjectFrame(cellX, 2);
        }
    }
}
