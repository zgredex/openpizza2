/* Game_HasRecordField14DC: checks whether any record in the map carries the
   given field 0x14dc value (0x4e0f40). */
struct IDMap {
    int *Lookup(int key, int *unused);
};

struct GameRecords {
    bool HasRecordField14DC(int value);
};

bool GameRecords::HasRecordField14DC(int value)
{
    char *self = (char *)this;
    int count = *(int *)(self + 0x15c);
    int i;

    for (i = 0; i < count; i++) {
        int *record = ((IDMap *)(self + 0x148))->Lookup(i, 0);

        if (*(int *)((char *)record + 0x14dc) == value)
            return true;
    }
    return false;
}
