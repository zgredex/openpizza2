/* Game_ComputePlayerSalary (0x4e3820). */
struct City {
    char pad0[0x40];
    int field40;            /* 0x40 */
    char pad1[0x14];        /* to 0x58 */
    int field58;            /* 0x58 */
};
struct Game {
    char pad0[0x68];
    int salaryType;         /* 0x68 */

    int GetPlayerFieldC20();
    City *GetPlayerCity();
    int ComputePlayerSalary();
};

int Game::ComputePlayerSalary()
{
    int type = salaryType;
    int field = GetPlayerFieldC20();
    int base;

    if (type == 1) {
        if (field <= 4)
            return -1;
        base = 20000;
        goto compute;
    }
    if (type == 2) {
        if (field <= 5)
            return -1;
        base = 40000;
    } else {
        return -1;
    }
compute:
    {
        City *city = GetPlayerCity();

        return (((10 - city->field58) - city->field40) * base * 10) / 100;
    }
}
