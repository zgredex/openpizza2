/* Game_CanShowObject: visibility test for a map object (0x4d2fd0). */
extern "C" int DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    int CountRecordsByOwner(int owner);
};

extern "C" int __fastcall Game_CanShowObject(int object)
{
    struct Game *record = (struct Game *)
        ((struct IDMap *)(DAT_0057c670 + 4))->Lookup(*(int *)(object + 0x28), 0);
    int count = record->CountRecordsByOwner(*(int *)(object + 4));

    if (*(int *)(object + 4) == 0x23)
        return 1;
    if (*(int *)(object + 0x50) == 0 || count <= 1)
        return 0;
    return 1;
}
