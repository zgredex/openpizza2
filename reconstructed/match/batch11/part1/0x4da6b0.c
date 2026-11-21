/* Player_HasRecordWithField30: reports whether the player owns a record of
   the requested type (0x4da6b0). */
extern "C" int *DAT_0057c670;

struct IDMapHelper {
    void *Lookup(int index, int *result);
};

struct Game {
    char *GetPlayerBySlot(int slot);
};

extern "C" bool __stdcall Player_HasRecordWithField30(int type, int slot)
{
    char *player = ((Game *)DAT_0057c670)->GetPlayerBySlot(slot);
    int count = *(int *)(player + 0x194);
    int index = 0;

    for (index = 0; index < count; index++) {
        char *record =
            (char *)((IDMapHelper *)(player + 0x180))->Lookup(index, 0);

        if (*(int *)(record + 0x30) == type)
            return 1;
    }
    return 0;
}
