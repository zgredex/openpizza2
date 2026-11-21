/* Game_CountObjectsType1DSub19: counts records of type 0x1d whose subtype is
   0x19 (0x480070). */
struct GameMap {
    int MapRecordToGlobal(int index);
};

extern "C" int __fastcall Game_CountObjectsType1DSub19(int param_1)
{
    int count = 0;
    int i = 0;
    void *map = *(void **)(param_1 + 0x16f0);
    int record;

    if (0 < *(int *)((char *)map + 0x8c)) {
        do {
            record = ((GameMap *)map)->MapRecordToGlobal(i);
            if (*(int *)((char *)record + 0x30) == 0x1d &&
                *(int *)((char *)record + 0xa4) == 0x19)
                count++;
            map = *(void **)(param_1 + 0x16f0);
            i++;
        } while (i < *(int *)((char *)map + 0x8c));
    }
    return count;
}
