/* Game_HasKeyedRecordEntry: finds an entry by two keys (0x48c020). */
struct Array {
    void *Lookup(int key, int *out);
    int FindEntryByKeys(int key, int value);
};

struct Game {
    char pad[0x304];
    Array records;
    void HasKeyedRecordEntry(int key, int value);
};

void Game::HasKeyedRecordEntry(int key, int value)
{
    records.FindEntryByKeys(key, value);
}
