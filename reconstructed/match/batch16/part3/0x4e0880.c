/* Game_FindDailyStatRecord: finds the daily statistics record matching the
   requested day and variant (0x4e0880). */
extern int DAT_0057c670;
extern int DAT_0057dfbc;

struct IDMap {
    void *Lookup(int index, int *out);
};

class Game {
public:
    int FindDailyStatRecord(int slot, unsigned day, int variant);
};

int Game::FindDailyStatRecord(int param_1, unsigned param_2, int param_3)
{
    int iVar1;
    int iVar2;
    int iVar3;

    iVar1 = *(int *)((char *)this + 0x178);
    if (param_3 == -1) {
        if (param_2 == *(unsigned short *)(*(int *)(DAT_0057c670 + 0x94) + 4)) {
            param_3 = *(unsigned char *)(*(int *)(DAT_0057c670 + 0x94) + 8) +
                      (param_2 - DAT_0057dfbc) * 4;
        } else {
            param_3 = (param_2 - DAT_0057dfbc) * 4 + 3;
        }
    }
    for (iVar3 = 0; iVar3 < iVar1; iVar3++) {
        iVar2 = (int)((IDMap *)((char *)this + 0x164))->Lookup(iVar3, 0);
        if ((*(unsigned int *)(iVar2 + 8) == param_2) &&
            (param_3 == *(int *)(iVar2 + 4))) {
            return param_1 * 0x20 + 0xdc + iVar2;
        }
    }
    return 0;
}
