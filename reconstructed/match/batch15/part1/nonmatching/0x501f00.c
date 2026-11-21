/* Stats_GetCityShareRank: ranks the player's city market share against all
   cities (0x501f00). */
extern int *DAT_0057c670;

struct City {
    char pad[0xa0];
    int share;
};

struct Player {
    City *GetPlayerCity();
};

struct Game {
    Player *GetPlayerBySlot(int slot);
};

extern "C" int Stats_GetCityShareRank()
{
    int total = 0;
    int i;

    for (i = 0; i < 6; i++) {
        Player *player = ((Game *)DAT_0057c670)->GetPlayerBySlot(i);

        if (player != 0) {
            City *city = player->GetPlayerCity();
            total = total + city->share;
        }
    }
    {
        City *city = ((Player *)*(int *)((char *)DAT_0057c670 +
                        *(int *)((char *)DAT_0057c670 + 0x2ec) * 4 + 0x200))
                         ->GetPlayerCity();

        if (total > 0) {
            int share = city->share * (100 / total);

            if (share > 0x3c) {
                return 3;
            }
            if (share > 0x30) {
                return 2;
            }
            if (share != 0) {
                return 1;
            }
        }
    }
    return 0;
}
