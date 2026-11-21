/* Game_GetPlayerSubrecord: looks up a player subrecord, optionally hiding
   flagged records (0x500e80). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    void *GetPlayerSubrecord(int slot, int key, int checkFlag);
};

void *Game::GetPlayerSubrecord(int slot, int key, int checkFlag)
{
    char *player = *(char **)((char *)this + slot * 0x168 + 0x70);
    void *record = ((IDMap *)(player + 0x148))->Lookup(key, 0);

    if (checkFlag != 0 && record != 0 && *(char *)((char *)record + 0x16f5) != 0)
        record = 0;
    return record;
}
