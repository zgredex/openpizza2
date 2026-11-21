/* Game_FindRecordByPair: finds a record by its key pair (0x47cd30). */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct PairRecord {
    char pad[0x18];
    int first;
    int second;
};

struct Game {
    char pad[0x16f8];
    char map[0x14];
    int count;

    struct PairRecord *FindRecordByPair(int first, int second);
};

struct PairRecord *Game::FindRecordByPair(int first, int second)
{
    int i;

    for (i = 0; i < count; i++) {
        struct PairRecord *record =
            (struct PairRecord *)((struct IDMap *)map)->Lookup(i, 0);

        if (record->first == first && record->second == second) {
            return record;
        }
    }
    return 0;
}
