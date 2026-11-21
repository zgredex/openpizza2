/* Game_FindRecordByField34: finds a record whose field 0x34 matches
   (0x4e2330). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    char pad[0x180];
    int count;
    int FindRecordByField34(int value);
};

int Game::FindRecordByField34(int value)
{
    int count = *(int *)((char *)this + 0x194);
    int index = 0;

    while (index < count) {
        void *record =
            ((struct IDMap *)((char *)this + 0x180))->Lookup(index, 0);

        if (*(int *)((char *)record + 0x34) == value)
            return (int)record;
        index++;
    }
    return 0;
}
