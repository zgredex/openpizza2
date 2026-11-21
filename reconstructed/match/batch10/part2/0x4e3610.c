/* Game_ComputeActionCost: action cost scaled by the player's city
   properties (0x4e3610). */
extern "C" int DAT_0056d104[];

struct Game {
    void *GetPlayerCity(void);
};

extern "C" int __fastcall Game_ComputeActionCost(int player)
{
    int base;

    if (*(int *)(player + 0x64) > 2)
        return 0;
    base = DAT_0056d104[*(int *)(player + 0x64)];
    {
        char *city = (char *)((struct Game *)player)->GetPlayerCity();

        return ((100 - (*(int *)(city + 0x68) + *(int *)(city + 0x50)) * 30)
                * base) / 100;
    }
}
