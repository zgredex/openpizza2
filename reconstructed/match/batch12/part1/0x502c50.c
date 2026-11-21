/* Building_GetRandomResidentCount: chooses a random resident count for a
   building type (0x502c50). */
extern int DAT_0057c670;
extern int DAT_005727fc[];
int __cdecl Random_RangeFast(int low, int high);

struct Player {
    int GetPlayerFieldC20();
};

struct Building {
    char pad[0x44];
    int residents;

    int GetRandomResidentCount(int type);
};

int Building::GetRandomResidentCount(int type)
{
    int random = Random_RangeFast(0, 1);
    int index = residents;
    struct Player *player = *(struct Player **)(
        DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
    int value = player->GetPlayerFieldC20();

    if (value > 0 && type == 6 && residents == 0) {
        index = 1;
    }
    return DAT_005727fc[index + (random + type * 2) * 4];
}
