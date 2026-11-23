/* Game_GetObjectStatusLevel: classifies the state of a building for the
   current player (0x50e550). */
extern int DAT_0057c670;

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    int GetCurrentPlayerCompanyName();
};

struct Rating {
    int AdjustB();
};

extern "C" int __fastcall Game_GetObjectStatusLevel(int param_1)
{
    int iVar1;
    int iVar2;
    int iVar3;

    iVar1 = (int)((IDMap *)(DAT_0057c670 + 0x20))
               ->Lookup(*(int *)(param_1 + 0x50), 0);
    iVar3 = *(int *)(iVar1 + 0x81c);
    iVar2 = ((Game *)DAT_0057c670)->GetCurrentPlayerCompanyName();
    if (iVar3 == iVar2) {
        iVar3 = ((Rating *)iVar1)->AdjustB();
        if (iVar3 < 0x14) {
            return 1;
        }
        if (0 < *(int *)(iVar1 + 0x14)) {
            return 2;
        }
        if (0 < *(int *)(iVar1 + 0x18)) {
            return 2;
        }
        if (0 < *(int *)(iVar1 + 0x20)) {
            return 3;
        }
        if (*(int *)(iVar1 + 0xc) < 0x14) {
            return 4;
        }
        if (*(int *)(param_1 + 0x30) == 0x14) {
            return (*(char *)(iVar1 + 0x825) != '\x02') ? 7 : 0;
        }
    }
    return 0;
}
