/* Game_FindRecordByField4: finds a record whose field 4 matches (0x4ddce0). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    char pad[0x164];
    int count;
    int FindRecordByField4(int value);
};

int Game::FindRecordByField4(int value)
{
    int count = *(int *)((char *)this + 0x178);
    int index = 0;

    while (index < count) {
        void *record =
            ((struct IDMap *)((char *)this + 0x164))->Lookup(index, 0);

        if (*(int *)((char *)record + 4) == value)
            return (int)record;
        index++;
    }
    return 0;
}
