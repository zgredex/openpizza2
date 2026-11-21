/* Game_UpgradeProductionLevel (0x4e3660). */
extern char *DAT_0057c670;
struct Game {
    char pad0[0x180];
    int counter;            /* 0x180 */
};
struct Service {
    int ComputeActionCost();
    char CanAffordWithCurrency(int currency, float amount, char flag,
                               int other);
    void AdvanceProductionCounter();
    int UpgradeProductionLevel();
};

int __fastcall Game_UpgradeProductionLevel(Service *service)
{
    int isCurrent = (int)service ==
        *(int *)(DAT_0057c670 + 0x200 +
                 *(int *)(DAT_0057c670 + 0x2ec) * 4);
    int cost = service->ComputeActionCost();

    if (cost != 0) {
        Game *game;

        if (isCurrent &&
            *(int *)(*(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8) + 0x180)
                != 0) {
            cost = (cost * 0xf) / 10;
        }
        if (service->CanAffordWithCurrency(10, (float)cost, 1, -1) == 0)
            return 0;
        if (isCurrent) {
            game = (Game *)*(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
            if (game->counter != 0)
                game->counter = game->counter - 1;
        }
        service->AdvanceProductionCounter();
    }
    return 1;
}
