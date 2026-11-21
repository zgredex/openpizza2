/* Game_FindRecordByField24: linear search of the map records by the field at
   offset 0x24 (0x4d7600). */
struct IDMap {
    int *Lookup(int key, int *out);
};

struct Game {
    int *FindRecordByField24(int value);
};

int *Game::FindRecordByField24(int value)
{
    int index;

    for (index = 0; index < *(int *)((char *)this + 0xfc0); index++) {
        int *record = ((struct IDMap *)((char *)this + 0xfac))->Lookup(index, 0);

        if (*(int *)((char *)record + 0x24) == value)
            return record;
    }
    return 0;
}
