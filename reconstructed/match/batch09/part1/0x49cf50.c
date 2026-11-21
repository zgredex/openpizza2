/* Game_SyncSelectedPlayerCompany: copies the selected player's company id
   into the game state and notifies the UI (0x49cf50). */
struct Player {
    char pad[0x1d4];
    int company;
};

struct Game {
    struct Player *GetPlayerBySlot(int slot);
};

struct UI {
    void QueueControlCommand(int command, int arg, int value);
};

extern struct Game *DAT_0057c670;
extern int DAT_0057cab4;
extern int DAT_0057ca98;

void __cdecl Game_SyncSelectedPlayerCompany(void)
{
    struct Player *player = DAT_0057c670->GetPlayerBySlot(DAT_0057cab4);

    DAT_0057ca98 = player->company;
    if (*(int *)((char *)DAT_0057c670 + 0x98) != DAT_0057ca98)
        ((struct UI *)*(void **)((char *)DAT_0057c670 + 0x25c))
            ->QueueControlCommand(-0x18670, 0x23, DAT_0057ca98);
}
