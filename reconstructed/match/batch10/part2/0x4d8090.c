/* Game_GetMostAdvancedCompany: company with the highest advancement value
   (0x4d8090). */
extern "C" int DAT_0057c670;

struct Game {
    int GetCurrentPlayerCompanyName(void);
};

extern "C" int __fastcall Game_GetMostAdvancedCompany(int data)
{
    int index;

    if (*(int *)(*(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8) + 0xf8) != 0)
        return ((struct Game *)DAT_0057c670)->GetCurrentPlayerCompanyName();
    {
        unsigned int bestValue = 0;
        int best = -1;

        for (index = 0; index < 6; index++) {
            unsigned int value = *(unsigned int *)(data + 0xdac + index * 4);

            if (value > bestValue) {
                bestValue = value;
                best = index;
            }
        }
        return best;
    }
}
