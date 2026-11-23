/* Game_GetBuildingQualityBand (0x502030). */

extern char *DAT_0057c670;

struct IDMapHelper {
    char pad[0x14];

    void *Lookup(int key, int *out);
};

struct Rating {
    char pad0[0x0c];
    int value;                  /* 0x0c */

    int AdjustB();
};

struct Game {
    int CountObjectsByType(int type);
};

struct Player {
    char pad0[0x148];
    IDMapHelper map;            /* 0x148 */
    int count;                  /* 0x15c */
};

struct Object {
    char pad0[0x1500];
    IDMapHelper map;            /* 0x1500 */
};

extern "C" int Game_GetBuildingQualityBand(void)
{
    int best = 0;
    int index = 0;
    Player *player = *(Player **)(DAT_0057c670 + 0x200 +
                                  *(int *)(DAT_0057c670 + 0x2ec) * 4);
    int count = player->count;

    if (count > 0) {
        do {
            Object *object = (Object *)player->map.Lookup(index, 0);
            int total = ((Game *)object)->CountObjectsByType(-1);
            int sum = 0;
            int j = 0;

            if (total > 0) {
                do {
                    int *entry =
                        (int *)((IDMapHelper *)((char *)object + 0x1500))
                            ->Lookup(j, 0);
                    int value = *(int *)(*entry + 0xc);
                    int adjust = ((Rating *)*entry)->AdjustB();

                    sum = sum + (adjust + value);
                    j++;
                } while (j < total);
            }
            if (total == 0)
                sum = 0;
            else
                sum = sum / (total * 2);
            if (sum > best)
                best = sum;
            index++;
        } while (index < count);
        if (best > 0x50)
            return 3;
        if (best > 0x3b)
            return 2;
        if (best > 0x28)
            return 1;
    }
    return 0;
}
