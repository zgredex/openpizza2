/* Game_DecayCityDateBonus (0x4e46f0). */
extern double DAT_0055c310;
extern double DAT_0055c5b0;
extern double DAT_0055c5a8;

struct Game {
    char pad0[0x10];
    double value;           /* 0x10 */
    char pad1[4];           /* to 0x1c */
    char flag;              /* 0x1c */

    void DecayCityDateBonus();
    void ComputeCityDateBonus();
};

void Game::DecayCityDateBonus()
{
    if (flag == 0) {
        if (value > DAT_0055c310) {
            value = value - DAT_0055c5b0;
            if (value >= DAT_0055c310)
                goto done;
        } else {
            if (value >= DAT_0055c310)
                goto done;
            {
                double next = value;

                next += DAT_0055c5a8;
                value = next;
                if (next <= DAT_0055c310)
                    goto done;
            }
        }
        value = 0.0;
    }
done:
    flag = 0;
    ComputeCityDateBonus();
}
