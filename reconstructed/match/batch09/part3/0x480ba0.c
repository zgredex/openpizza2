/* Game_CountRecordsWithFieldA0: counts mapped records whose field 0xa0 is
   non-zero (0x480ba0). */
struct GameMap {
    int MapRecordToGlobal(int index);
};

extern "C" int __fastcall Game_CountRecordsWithFieldA0(int param_1)
{
    GameMap *map = *(GameMap **)(param_1 + 0x16f0);
    int count = 0;
    int i;
    int record;

    if (map != 0) {
        for (i = 0; i < *(int *)((char *)map + 0x8c); i++) {
            record = map->MapRecordToGlobal(i);
            if (record != 0 && *(int *)((char *)record + 0xa0) != 0)
                count++;
        }
    }
    return count;
}
