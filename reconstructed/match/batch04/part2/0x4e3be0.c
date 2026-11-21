/* Player_ResetDebtHours: clears the debt clock once it is non-negative (0x4e3be0). */
extern double DAT_0055c310;

void __fastcall Player_ResetDebtHours(char *player)
{
    if (*(double *)(player + 0x108) >= DAT_0055c310)
        *(int *)(player + 0x1e8) = 0;
}
