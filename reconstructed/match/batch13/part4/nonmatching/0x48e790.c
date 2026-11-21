/* Game_GetNextRecordField3C (0x48e790). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
struct Map {
    int FindIndex(void *record);
};
extern "C" char *DAT_0057c670;

extern "C" int Game_GetNextRecordField3C(int key, int flag)
{
    int skipped = 0;
    char *table = DAT_0057c670;
    int record = *(int *)(table + 0x200 + *(int *)(table + 0x2ec) * 4);
    int count = *(int *)(record + 0x15c);
    char *map = (char *)(record + 0x148);
    int index = ((struct Map *)map)->FindIndex(
        ((struct IDMap *)map)->Lookup(key, 0));
    void *item;

    while (1) {
        index = index + 1;
        if (count <= index) {
            index = 0;
        }
        item = ((struct IDMap *)map)->Lookup(index, 0);
        if (flag != 0 || *(int *)((char *)item + 0x38) < 2) {
            break;
        }
        skipped = skipped + 1;
        if (skipped >= count) {
            return 0;
        }
    }
    return *(int *)((char *)item + 0x3c);
}
