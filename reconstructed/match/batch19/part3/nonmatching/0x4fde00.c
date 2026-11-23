/* AI_SendGraffitiPunk (0x4fde00). */

extern char *DAT_0057c670;
extern int DAT_0057bb24;

extern "C" int Random_RangeFast(int min, int max);

struct Object {
    void SetDestinationAndTarget(int code, int target);
    void SetFieldA4Locked(int value);
};

struct City {
    char pad0[0x40];
    int v40;                    /* 0x40 */
    char pad1[0x14];
    int v58;                    /* 0x58 */
};

struct Game {
    void *FindFreeObjectByType(int type);
    int UpdateFreeBuildingCount();
    int CountFreeBuildingsByType(int type);
    City *GetPlayerCity();
    void CanAffordWithCurrency(int type, float value, int a, int b);
};

struct Player {
    char pad0[0x48];
    int field48;                /* 0x48 */
    char pad1[0x24];
    int counter;                /* 0x70 */
    char pad2[0x1680];
    int owner;                  /* 0x16f0 */
};

extern "C" int __stdcall AI_SendGraffitiPunk(Player *player, Player *record)
{
    Object *target = (Object *)((Game *)DAT_0057c670)->FindFreeObjectByType(0x16);

    if (target == 0)
        return 3;
    if (((Game *)record)->UpdateFreeBuildingCount() > 0) {
        unsigned value = Random_RangeFast(0, 10);

        if ((int)value < DAT_0057bb24)
            return 3;
    }
    if (((Game *)record)->CountFreeBuildingsByType(0x16) > 0)
        return 3;

    City *city = ((Game *)player)->GetPlayerCity();

    ((Game *)player)->CanAffordWithCurrency(
        0x17, (float)((((10 - city->v58) - city->v40) * 10000) / 100), 1,
        -1);
    target->SetDestinationAndTarget(1, record->owner);
    target->SetFieldA4Locked(1);
    *(int *)((char *)target + 0x110) = player->field48;
    player->counter = player->counter + 1;
    return 1;
}
