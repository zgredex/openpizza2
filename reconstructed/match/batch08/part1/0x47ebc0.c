/* Game_FindRecordByField10: finds a record whose field 0x10 matches
   (0x47ebc0). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    char pad[0x19c4];
    int count;
    int FindRecordByField10(int value);
};

int Game::FindRecordByField10(int value)
{
    int count = *(int *)((char *)this + 0x19d8);
    int index = 0;

    while (index < count) {
        void *record =
            ((struct IDMap *)((char *)this + 0x19c4))->Lookup(index, 0);

        if (*(int *)((char *)record + 0x10) == value)
            return (int)record;
        index++;
    }
    return 0;
}
