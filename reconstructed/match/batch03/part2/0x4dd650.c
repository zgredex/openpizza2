/* Game_SetGlobalWord16 - 0x4dd650, 21 bytes */
extern unsigned int DAT_0057dfbc;

struct Game
{
    char pad[4];
    unsigned short word;

    void SetGlobalWord16(unsigned short value);
};

void Game::SetGlobalWord16(unsigned short value)
{
    word = value;
    DAT_0057dfbc = value;
}
