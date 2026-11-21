/* Player_FindRecordByCityId: finds the player record whose lookup table
   contains the city id of the given record (0x4e23b0). */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct Record {
    bool HasKey(int key);
};

struct Player {
    char pad[0x180];
    char map[0x14];
    int count;

    struct Record *FindRecordByCityId(void *city);
};

struct Record *Player::FindRecordByCityId(void *city)
{
    int key = *(int *)((char *)city + 0x3c);
    int total = count;
    int i;

    for (i = 0; i < total; i++) {
        struct Record *record =
            (struct Record *)((struct IDMap *)map)->Lookup(i, 0);

        if (record->HasKey(key)) {
            return record;
        }
    }
    return 0;
}
