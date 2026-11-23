/* Game::GetAverageCompanyValueByByte8 (0x47cb70). */
extern "C" char *g_Game;
extern "C" int Math_RoundFloat(float value);

struct IDMapHelper {
    int data0;
    int data1;
    int data2;
    int data3;
    int data4;
    void *Lookup(int key, int *index);
};

struct Game {
    char pad[0x16f8];
    IDMapHelper players;
    int playerCount;
    char GetPlayerByte8();
    int GetAverageCompanyValueByByte8(char type);
};

struct Player {
    int id;
    int companyId;
};

struct Company {
    char pad[0x70];
    double value;
};

int Game::GetAverageCompanyValueByByte8(char type)
{
    int count;
    float sum;
    int i;

    count = 0;
    sum = 0.0f;
    i = 0;
    if (playerCount > 0) {
        do {
            Player *record = (Player *)players.Lookup(i, 0);
            if (((Game *)record)->GetPlayerByte8() == type) {
                IDMapHelper *companies = (IDMapHelper *)(g_Game + 0x74);
                int companyId = record->companyId;
                Company *company = (Company *)companies->Lookup(companyId, 0);
                double value = company->value;
                sum = value + sum;
                count++;
            }
            i++;
        } while (i < playerCount);
        if (count > 0)
            return Math_RoundFloat(sum / (float)count);
    }
    return 0;
}
