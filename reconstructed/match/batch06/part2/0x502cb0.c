/* Game_PickRandomTableValue: indexes the random table with the slot twice (0x502cb0). */
extern "C" int Random_RangeFast(int low, int high);
extern int DAT_005728dc[];

struct Game {
    char pad[0x44];
    int slot;
    int PickRandomTableValue(int value);
};

int Game::PickRandomTableValue(int value)
{
    int random = Random_RangeFast(0, 1);

    return DAT_005728dc[slot + (random + value * 2) * 4];
}
