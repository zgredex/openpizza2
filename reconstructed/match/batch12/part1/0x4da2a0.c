/* City_ChargePoliceBribes: charges police protection money for each player
   (0x4da2a0). */
extern int DAT_0057c670;

struct Player;

struct Game {
    Player *GetPlayerBySlot(int slot);
};

struct Player {
    char CanAffordWithCurrency(int currency, float amount, char flag, int reason);
};

struct City {
    char pad[0xcb0];
    int bribes[6];

    void SetPlayerAdvertisingBudget(int slot, int value);
    void ChargePoliceBribes();
};

void City::ChargePoliceBribes()
{
    int i;

    for (i = 0; i < 6; i++) {
        Player *player = ((Game *)DAT_0057c670)->GetPlayerBySlot(i);

        if (player != 0 && bribes[i] != 0) {
            if (!player->CanAffordWithCurrency(0x15, (float)bribes[i], 1, -1)) {
                SetPlayerAdvertisingBudget(i, 0);
            }
        }
    }
}
