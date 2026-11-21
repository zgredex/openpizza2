/* Game_InitPlayerSlotTables (0x4f6fb0). */
struct Player;
struct Game {
    char pad0[0x224];
    Player *slots[6];       /* 0x224 */

    void *GetPlayerBySlot(int slot);
    void *GetPlayerField8(int index);
};
extern Game *DAT_0057c670;

void __fastcall Game_InitPlayerSlotTables(Game *game)
{
    int index = 0;
    int offset = 0x224;
    int *slot = (int *)((char *)game + 0x114);

    do {
        Player *player = *(Player **)((char *)(offset + (int)DAT_0057c670));

        if (player == 0) {
            slot[1] = 0;
            slot[0] = 0;
        } else {
            int playerKey = *(int *)((char *)player + 8);

            slot[-0x2a] = (int)player;
            slot[-0x29] = (int)DAT_0057c670->GetPlayerBySlot(playerKey);
            slot[-0x35] = (int)DAT_0057c670->GetPlayerField8(index);
        }
        offset += 4;
        index++;
        slot += 0x5a;
    } while (offset < 0x23c);
}
