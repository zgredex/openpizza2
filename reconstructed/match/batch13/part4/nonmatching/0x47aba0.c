/* Game_GetMarketBonus (0x47aba0). */
struct Rating {
    int GetComposite();
};
struct Game {
    char pad00[0x14c0];
    int field14c0;
    int field14c4;
    char pad14c8[0x8];
    int field14d0;

    int GetMarketBonus();
};

int Game::GetMarketBonus()
{
    int value;

    if (field14c4 == 0) {
        return 0;
    }
    value = (field14d0 + field14c0) >> 2;
    if (value < 0) {
        int rating = ((struct Rating *)field14c4)->GetComposite();
        if (rating / 0x14 > 0) {
            return value;
        }
        rating = ((struct Rating *)field14c4)->GetComposite();
        value = value + rating / 0x14;
    }
    return value;
}
