/* Game_SumPlayerAssetValue (0x4f7a50). */

extern char *DAT_0057c670;

struct IDMapHelper {
    char pad[0x14];

    void *Lookup(int key, int *out);
};

struct Game {
    void *GetPlayerBySlot(int slot);
    int CountObjectsByType(int type);
};

struct Player {
    char pad0[0x148];
    IDMapHelper objects;        /* 0x148 */
    char pad1[0x24];
    IDMapHelper entries;        /* 0x180 */
    int entryCount;             /* 0x194 */
};

extern "C" int __stdcall Game_SumPlayerAssetValue(int slot)
{
    Player *player = (Player *)((Game *)DAT_0057c670)->GetPlayerBySlot(slot);
    int count = *(int *)((char *)player + 0x15c);
    int total = 0;
    int value = 0;
    int index = 0;

    if (count > 0) {
        do {
            void *object = player->objects.Lookup(index, 0);

            if (object != 0) {
                int objects = ((Game *)object)->CountObjectsByType(-1);
                int j = 0;

                if (objects > 0) {
                    do {
                        int *entry =
                            (int *)((IDMapHelper *)((char *)object + 0x1500))
                                ->Lookup(j, 0);

                        if (*entry != 0)
                            total = total + *(int *)(*entry + 0x3c);
                        j++;
                    } while (j < objects);
                }
                value = *(int *)((char *)object + 0x14b0);
            }
            index++;
        } while (index < count);
    }
    int extra = 0;
    int entryCount = player->entryCount;
    int k = 0;

    if (entryCount > 0) {
        do {
            int entry = (int)player->entries.Lookup(k, 0);

            if (entry != 0 && *(char *)(entry + 0x3c) == 0)
                extra = extra + *(int *)(entry + 0x40);
            k++;
        } while (k < entryCount);
    }
    return value + extra + total;
}
