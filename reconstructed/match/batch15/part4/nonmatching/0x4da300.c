/* Non-matching candidate.
   First difference: offset 0x09, 9 bytes differ.
   the zero stores and the GetPlayerCity this-register load are scheduled in the opposite order.
   Kept for evidence; not part of the strict match set. */
extern void *DAT_0057c670;

struct Game {
    void *GetPlayerBySlot(int slot);
};

struct Player {
    int CanAffordWithCurrency(int currency, float amount, char mode, int limit);
    int GetPlayerCity();
};

void __fastcall Game_ChargeQuarterlyBribes(char *self)
{
    int index = 0;
    int *slot = (int *)(self + 0xcc8);
    do {
        char *player = (char *)((Game *)DAT_0057c670)->GetPlayerBySlot(index);
        if (player != 0 && slot[0x39] != 0) {
            unsigned char ok = ((Player *)player)->CanAffordWithCurrency(
                0x14, (float)(unsigned)slot[0x39], 1, -1);
            if (ok == 0) {
                slot[0x39] = 0;
                *slot = 0;
                int city = ((Player *)player)->GetPlayerCity();
                int value = *slot +
                            (*(int *)(city + 0x60) + *(int *)(city + 0x48)) * 3;
                *slot = value;
                if (value < 0)
                    *slot = 0;
                if (*slot > 100)
                    *slot = 100;
            }
        }
        index++;
        slot++;
    } while (index < 6);
}
