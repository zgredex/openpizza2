/* Game_InitCompanyAIStrategy (0x4dce00). */
struct Player {
    char pad0[0x50];
    int field50;            /* 0x50 */
};
struct Game {
    char pad0[0x1148];
    unsigned int field1148; /* 0x1148 */
    int field114c;          /* 0x114c */
    int field1150;          /* 0x1150 */
    int field1154;          /* 0x1154 */

    void InitCompanyAIStrategy();
    Player *GetPlayerBySlot(int slot);
};
extern Game *DAT_0057c670;
extern unsigned int Random_RangeFast(int minimum, int maximum);

void Game::InitCompanyAIStrategy()
{
    int empty = -1;
    int index = 0;

    do {
        Player *player = DAT_0057c670->GetPlayerBySlot(index);

        if (player != 0 && player->field50 == 0)
            empty++;
        index++;
    } while (index < 6);
    field1148 = Random_RangeFast(0, 7);
    index = 12 / empty;
    field1150 = empty * 5000;
    index += 3;
    field114c = index;
    field1154 = index;
}
