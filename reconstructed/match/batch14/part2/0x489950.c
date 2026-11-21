/* Game_CountPlayerRecordsByField34 (0x489950): counts the player records
   whose field 0x34 matches the given game's field 0xc1c across all slots. */
struct IDMap {
    int Lookup(int key, int *out);
};

struct Game {
    char pad[0x148];
    IDMap records;             /* 0x148 */
    char pad2[0x15c - 0x154];
    int recordCount;           /* 0x15c */
    void *GetPlayerBySlot(int slot);
    int CountPlayerRecordsByField34(void *game);
};

int Game::CountPlayerRecordsByField34(void *game)
{
    int count;
    int slot;
    void *player;
    int recordCount;
    int index;
    int record;
    IDMap *map;

    count = 0;
    slot = 0;
    do {
        player = GetPlayerBySlot(slot);
        if (player != 0) {
            recordCount = *(int *)((char *)player + 0x15c);
            index = 0;
            if (0 < recordCount) {
                map = (IDMap *)((char *)player + 0x148);
                do {
                    record = map->Lookup(index, 0);
                    if (*(int *)(record + 0x34) ==
                        *(int *)((char *)game + 0xc1c)) {
                        count = count + 1;
                    }
                    index = index + 1;
                } while (index < recordCount);
            }
        }
        slot = slot + 1;
    } while (slot < 6);
    return count;
}
