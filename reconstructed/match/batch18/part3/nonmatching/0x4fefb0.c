extern char *DAT_0057c670;
extern char *DAT_0057ba0c;

/* AI_Annoy_SendGangsterGroup: sends a group of gangsters to harass a branch
   (0x4fefb0). */
struct Game {
    void *GetPlayerBySlot(int slot);
    int GetCurrentPlayerCompanyName();
};

struct AI {
    int CountAvailableTargets(int target);
    int OpenBranchesInCity(void *a, void *b);
    int HireCourier(void *a, void *b);
    int SendGangsterGroup(void *city, void *target);
};

extern "C" int __cdecl Random_RangeFast(int min, int max);
extern "C" int __cdecl Math_CompareRounded(void);
extern "C" void __cdecl Sound_SetTimeout(char *sound);

int AI::SendGangsterGroup(void *city, void *target)
{
    unsigned int count = 0;
    unsigned int available;
    int hired;

    ((Game *)DAT_0057c670)->GetPlayerBySlot(*(int *)((char *)target + 0x30));
    available = CountAvailableTargets(0x1e);
    if (available != 0) {
        if (OpenBranchesInCity(city, target) != 0) {
            if ((int)available < 4) {
                available = 3;
            }
            available = Random_RangeFast(1, available);
            if (Math_CompareRounded() == 0) {
                return 2;
            }
            if (0 < (int)available) {
                do {
                    hired = HireCourier(city, target);
                    count = count | (unsigned int)hired;
                    available = available - 1;
                } while (available != 0);
                if (count != 0) {
                    int player = *(int *)((char *)target + 0x30);

                    if (player == ((Game *)DAT_0057c670)->GetCurrentPlayerCompanyName()) {
                        Sound_SetTimeout(DAT_0057ba0c);
                    }
                }
            }
        }
    }
    return 1;
}
