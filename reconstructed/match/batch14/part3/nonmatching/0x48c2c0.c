/* Game_ApplyPercentChange (0x48c2c0): applies a percentage change to one
   value field of every matching record. */
struct Record {
    char pad[0x34];
    int group;
    char pad2[0x5c - 0x38];
    int values[1];
    char pad3[0xa0 - 0x60];
    int active;
};

struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *result);
};

struct Game {
    char pad[0x3c];
    IDMap recordMap;

    void ApplyPercentChange(int index, int percent, int filter);
};

void Game::ApplyPercentChange(int index, int percent, int filter)
{
    int count = recordMap.count;
    int i = 0;

    if (0 < count) {
        int value = index;

        do {
            Record *record = (Record *)recordMap.Lookup(i, 0);

            if (record->active != 0) {
                if (filter == -1 || record->group == filter)
                    value = record->values[index];
                value = (percent + 100) * value;
                record->values[index] = value / 100;
            }
            i++;
        } while (i < recordMap.count);
    }
}
