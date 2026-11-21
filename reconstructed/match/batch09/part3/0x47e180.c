/* Game_FindRecordByField20: searches the game's record map for an entry
   whose field 0x20 matches (0x47e180). */
struct IDMap {
    int *Lookup(int key, int *unused);
};

struct GameWorld {
    int FindRecordByField20(int value);
};

int GameWorld::FindRecordByField20(int value)
{
    int i = 0;
    int *record;
    char *self = (char *)this;

    while (i < *(int *)(self + 0x170c)) {
        record = ((IDMap *)(self + 0x16f8))->Lookup(i, 0);
        if (record != 0 && *(int *)((char *)record + 0x20) == value)
            return (int)record;
        i++;
    }
    return 0;
}
