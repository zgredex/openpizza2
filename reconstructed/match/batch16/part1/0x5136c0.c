extern char *DAT_0057c670;
class Game {
public:
    char pad0[0x264];
    int a264[8];
    int a284[8];
    int a2a4[8];
    int a2c4[8];
    int GetCurrentPlayerCompanyName();
    void ComputeCompanyRatings(int company);
};
void Game::ComputeCompanyRatings(int company)
{
    int bonus = 0;
    if (company == ((Game *)DAT_0057c670)->GetCurrentPlayerCompanyName()) {
        char *a = *(char **)(DAT_0057c670 + 0x224);
        char *b = *(char **)(a + 0xa8);
        bonus = (*(int *)(b + 0xe8) * 2 - *(int *)(b + 0x1cc)) * 5;
    }
    for (int i = 0; i < 8; i++) {
        int value = (((a264[i] + a284[i]) / 2 + a2a4[i]) * (bonus + 100)) / 100;
        a2c4[i] = value;
        if (value < 0) a2c4[i] = 0;
        if (a2c4[i] > 100) a2c4[i] = 100;
    }
}
