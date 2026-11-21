/* Player_FindRecordType2ByKey: finds a type-2 record by key (0x4e34a0). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Player {
    void *FindRecordType2ByKey(int key);
};

void *Player::FindRecordType2ByKey(int key)
{
    int count = *(int *)((char *)this + 0x140);
    int i = 0;

    if (count > 0) {
        IDMap *map = (IDMap *)((char *)this + 0x12c);
        do {
            char *record = (char *)map->Lookup(i, 0);
            if (*(int *)(record + 8) == 2 && *(int *)(record + 0xc) == key)
                return record;
            i++;
        } while (i < count);
    }
    return 0;
}
