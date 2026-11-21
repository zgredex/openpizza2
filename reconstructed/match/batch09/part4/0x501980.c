/* Game_GetRandomPlayerRecordValue: returns a random record value from a
   player's employee map (0x501980). */
extern "C" int Random_Mod(unsigned int range);

struct IDMap {
    int *Lookup(int key, int *unused);
};

struct PlayerSlots {
    int GetRandomPlayerRecordValue(int index);
};

int PlayerSlots::GetRandomPlayerRecordValue(int index)
{
    char *self = (char *)this;
    int **slot = (int **)(self + index * 0x168 + 0x70);
    unsigned int count;
    unsigned int randomIndex;
    int *record;
    int *player;

    count = *(unsigned int *)((char *)*slot + 0x15c);
    if (count == 0)
        return -1;
    randomIndex = Random_Mod(count);
    player = *slot;
    record = ((IDMap *)((char *)player + 0x148))->Lookup(randomIndex, 0);
    return *(int *)((char *)record + 0x3c);
}
