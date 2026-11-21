/* Game_FindRecordByPairChecked: finds a record by its key pair, rejecting null
   lookups (0x47e130). */
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

    struct PairRecord *FindRecordByPairChecked(int first, int second);
};

struct PairRecord *Game::FindRecordByPairChecked(int first, int second)
{
    int i;

    for (i = 0; i < count; i++) {
        struct PairRecord *record =
            (struct PairRecord *)((struct IDMap *)map)->Lookup(i, 0);

        if (record != 0 && record->first == first &&
            record->second == second) {
            return record;
        }
    }
    return 0;
}
