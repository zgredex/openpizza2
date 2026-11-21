/* IDMap_FindIndexByValue: looks up the record holding a value and returns the
   index stored by the map (0x47c370). */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    char pad[0x1500];
    char map[0x14];
    int count;

    int FindIndexByValue(int value);
};

int Game::FindIndexByValue(int value)
{
    int result;
    int i;

    if (value != 0) {
        int total = count;

        for (i = 0; i < total; i++) {
            int *record = (int *)((struct IDMap *)map)->Lookup(i, &result);

            if (value == *record) {
                return result;
            }
        }
    }
    return -1;
}
