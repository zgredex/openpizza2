/* Branch_GetMenuRating: returns the menu price rating for a branch, either
   averaged over all eight entries or for one index (0x478320). */
extern int DAT_0057c670;

struct Player {
    char pad[0x4c];
};

struct City {
    char pad[0x44];
    int field_44;
    char pad2[0x14];
    int field_5c;
};

struct Game {
    void *GetPlayerBySlot(int slot);
    void *GetPlayerCity();
};

class Branch {
public:
    int GetMenuRating(int index);
    void RecomputeMenuPriceRatings();
};

int Branch::GetMenuRating(int param_1)
{
    int iVar1;
    int *piVar2;
    int iVar3;
    int iVar4;

    iVar4 = 0;
    if (*(int *)((char *)this + 0x1714) == 0)
        RecomputeMenuPriceRatings();
    if (param_1 == -1) {
        piVar2 = (int *)((char *)this + 0x177c);
        iVar1 = 8;
        do {
            iVar4 = iVar4 + *piVar2;
            piVar2 = piVar2 + 1;
            iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
        iVar4 = iVar4 / 8;
    } else {
        iVar4 = *(int *)((char *)this + param_1 * 4 + 0x177c);
    }
    iVar3 = (int)((Game *)DAT_0057c670)->GetPlayerBySlot(
        *(int *)((char *)this + 0x30));
    iVar3 = (int)((Game *)iVar3)->GetPlayerCity();
    iVar4 = ((((City *)iVar3)->field_44 + ((City *)iVar3)->field_5c) * -3 + 100) *
            iVar4 / 100;
    if (iVar4 < 0)
        return 0;
    if (iVar4 > 100)
        iVar4 = 100;
    return iVar4;
}
