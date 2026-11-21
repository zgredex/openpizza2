/* Game_HasObjectWithSourceId: reports whether an object with the matching
   source id exists (0x50bba0). */
extern "C" int *DAT_0057c670;

struct IDMapHelper {
    void *Lookup(int index, int *result);
};

struct Game {
    int CountObjectsByState(int state);
};

extern "C" int __fastcall Game_HasObjectWithSourceId(char *this_)
{
    int sourceId = *(int *)(this_ + 0x164);
    int count = ((Game *)DAT_0057c670)->CountObjectsByState(-1);
    int index = 0;

    for (index = 0; index < count; index++) {
        char *object =
            (char *)((IDMapHelper *)((char *)DAT_0057c670 + 0x3c))
                ->Lookup(index, 0);

        if (*(int *)(object + 0x30) == 0x1d &&
            *(int *)(object + 0x10c) == sourceId)
            return 1;
    }
    return 0;
}
