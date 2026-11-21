/* Game_RemoveObjectFromList (0x4d2960). */
struct IDMap {
    char pad00[0x14];
    unsigned RemoveByKey(int key);
    void *Lookup(int key, int *out);
};
struct Set {
    void Field168(int value);
};
struct Object {
    void SetFieldFC(int value);
};
struct Map {
    void SetCellObjectFrame(int cell, int frame);
};
struct Game {
    char pad00[0x24];
    int field24;
    int field28;
    char pad2c[0x4c];
    struct IDMap map78;
    int field8c;

    unsigned RemoveObjectFromList(void *object, int flag);
};
extern "C" char *DAT_0057c670;

unsigned Game::RemoveObjectFromList(void *object, int flag)
{
    unsigned result = map78.RemoveByKey(*(int *)((char *)object + 0x164));

    ((struct Set *)object)->Field168(0);
    if (flag == 0) {
        ((struct Object *)object)->SetFieldFC(0);
    }
    if (field8c == 0) {
        int record = (int)((struct IDMap *)(DAT_0057c670 + 4))->Lookup(field28, 0);
        ((struct Map *)*(void **)(record + 0xfa8))->SetCellObjectFrame(
            field24, 1);
    }
    return result;
}
