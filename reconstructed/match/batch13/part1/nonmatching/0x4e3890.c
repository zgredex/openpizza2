/* Game_ComputePlayerTax (0x4e3890). */
struct City {
    char pad0[0x40];
    int field40;            /* 0x40 */
    char pad1[0x14];        /* to 0x58 */
    int field58;            /* 0x58 */
};
struct Game {
    char pad0[0x6c];
    int taxType;            /* 0x6c */

    int GetPlayerFieldC20();
    City *GetPlayerCity();
    int ComputePlayerTax();
};

int Game::ComputePlayerTax()
{
    int type = taxType;
    int field = GetPlayerFieldC20();
    int base;

    if (type == 1) {
        if (field <= 4)
            return -1;
        base = 30000;
    } else if (type == 2) {
        if (field <= 5)
            return -1;
        base = 60000;
    } else {
        return -1;
    }
    {
        City *city = GetPlayerCity();

        return (((10 - city->field58) - city->field40) * base * 10) / 100;
    }
}
