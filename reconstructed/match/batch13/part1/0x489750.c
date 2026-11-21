/* Game_FindRecordByTripleKey (0x489750). */
struct IDMap {
    char pad[0x14];
    void *Lookup(int key, int *out);
};
struct TripleRecord {
    char pad0[8];
    int first;              /* 0x08 */
    char pad1[4];           /* to 0x10 */
    int second;             /* 0x10 */
    unsigned char third;    /* 0x14 */
};
struct Game {
    char pad0[0x74];
    IDMap map;              /* 0x74 */
    int count;              /* 0x88 */

    TripleRecord *FindRecordByTripleKey(int first, int second,
                                        unsigned int third, int *out);
};

TripleRecord *Game::FindRecordByTripleKey(int first, int second,
                                         unsigned int third, int *out)
{
    int index;

    for (index = 0; index < count; index++) {
        TripleRecord *record = (TripleRecord *)map.Lookup(index, 0);

        if (record->first == first && record->second == second &&
            record->third == third) {
            if (out == 0)
                return record;
            *out = index;
            return record;
        }
    }
    return 0;
}
