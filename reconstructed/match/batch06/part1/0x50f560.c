/* Game_GetPlayerTotalValue: sums cash and two asset fields (0x50f560). */
struct Game {
    void *GetPlayerBySlot(int slot);
};

extern char *DAT_0057c670;

int __fastcall Game_GetPlayerTotalValue(char *record)
{
    char *player = (char *)((Game *)DAT_0057c670)->GetPlayerBySlot(
        *(int *)(record + 8));
    int *values = (int *)(player + 0x70);

    return values[6] + values[2] + values[1];
}
