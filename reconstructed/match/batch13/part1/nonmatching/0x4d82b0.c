/* Game_PickBestScoredRecord (0x4d82b0). */
struct IDMap {
    char pad[0x14];
    void *Lookup(int key, int *out);
};
struct Game {
    void *GetPlayerSubmapValue(int a, int b);
};
struct Player {
    char pad0[8];
    int field08;            /* 0x08 */
    char pad1[0x20];        /* to 0x2c */
    int field2c;            /* 0x2c */
};
struct ScoredRecord {
    char pad0[0x30];
    int scoreIndex;         /* 0x30 */
};
extern Game *DAT_0057c670;

void *__stdcall Game_PickBestScoredRecord(int table, IDMap *map)
{
    int index = 0;
    int best = -10000;
    int *scoreTable = (int *)table;
    void *result;

    if (*(int *)((char *)map + 0x14) > 0) {
        do {
            Player *player = (Player *)map->Lookup(index, 0);
            ScoredRecord *record = (ScoredRecord *)DAT_0057c670
                ->GetPlayerSubmapValue(player->field08, player->field2c);
            int value = scoreTable[record->scoreIndex + 0x17];

            if (value >= best) {
                best = value;
                result = player;
            }
            index++;
        } while (index < *(int *)((char *)map + 0x14));
        return result;
    }
    return map;
}
