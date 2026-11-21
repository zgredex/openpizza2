/* Game_ComputeRecordCompanyPrice (0x4e63f0, 47 bytes).  Build: /O2 /TP.
   Looks the record up in the company map and prices it; zero on a miss. */
extern int DAT_0057c670;
extern float DAT_0055c2e4;

struct IDMap {
    int Lookup(int key, int *out);
};

struct Game {
    float ComputePrice(int key);
    float ComputeRecordCompanyPrice(int key);
};

float Game::ComputeRecordCompanyPrice(int key)
{
    int recordKey = *(int *)((char *)this + 4);
    int record = ((IDMap *)(DAT_0057c670 + 0x74))->Lookup(recordKey, 0);

    if (record != 0)
        return ((Game *)record)->ComputePrice(key);
    return DAT_0055c2e4;
}
