/* Game_CountRecordsByPair: counts records matching a key pair (0x47cc70). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Record {
    char pad[4];
    int first;
    int second;
};

struct Game {
    char pad[0x16f8];
    char map[0x14];
    int count;

    int CountRecordsByPair(int first, int second);
};

int Game::CountRecordsByPair(int first, int second)
{
    int total = 0;
    int i;

    for (i = 0; i < count; i++) {
        struct Record *record = (struct Record *)((struct IDMap *)map)->Lookup(i, 0);

        if (record != 0 && record->first == first && record->second == second) {
            total++;
        }
    }
    return total;
}
