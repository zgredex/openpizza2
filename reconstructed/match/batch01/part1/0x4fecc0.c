/* AI_UpdateAdvertisingCampaigns: starts/stops AI advertising campaigns based
   on player totals (0x4fecc0). */
struct Game {
    int GetPlayerCount();
    void *GetPlayerBySlot(int slot);
};

struct Player {
    double ComputeNetStatTotal();
    void InitSlotFlags(int slot);
    void StopCampaign(int slot, int amount, int flag);
};

extern "C" {
extern int DAT_0057c670;
extern int DAT_0057bb24;
extern char *DAT_00580f04;
extern char *DAT_005816b4;
extern char *DAT_00581ab8;
extern char *DAT_00582984;
void __cdecl UI_Briefing_Printf(int game, int a, int b, int c, int d, int e,
                                char *fmt1, char *fmt2, int *value);
}

int __fastcall AI_UpdateAdvertisingCampaigns(void *this_, int unused, int param_1)
{
    int iVar1;
    int iVar2;
    int bVar3;
    int iVar4;
    void *this_00;
    int iVar6;
    int iVar7;
    int iVar8;

    iVar1 = *(int *)((char *)this_ + param_1 * 0x168 + 0x70);
    iVar2 = *(int *)((char *)this_ + param_1 * 0x168 + 0x40);
    iVar4 = ((Game *)DAT_0057c670)->GetPlayerCount();
    param_1 = 0;
    if (iVar4 > 0) {
        do {
            this_00 = ((Game *)DAT_0057c670)->GetPlayerBySlot(param_1);
            if (*(int *)((char *)this_00 + iVar2 * 4 + 0x94) != 0) {
                iVar7 = (int)((Player *)iVar1)->ComputeNetStatTotal();
                iVar8 = (int)((Player *)this_00)->ComputeNetStatTotal();
                bVar3 = iVar7 * 100 > (0x14 - DAT_0057bb24) * iVar8 * 10;
                if (*(char *)((char *)this_00 + iVar2 + 0xac) != '\0') {
                    iVar6 = iVar7 >> 3;
                    if (bVar3 || *(int *)((char *)this_00 + iVar2 * 4 + 0x94) > iVar6) {
                        ((Player *)this_00)->StopCampaign(iVar2, *(int *)(iVar1 + 0x48), 1);
                        if (this_00 ==
                            *(void **)(DAT_0057c670 +
                                       *(int *)(DAT_0057c670 + 0x2ec) * 4 + 0x200)) {
                            UI_Briefing_Printf(DAT_0057c670, -1, 4, -1, -1, 0,
                                               DAT_00580f04, DAT_005816b4,
                                               (int *)(iVar1 + 8));
                        }
                    }
                }
                else {
                    iVar6 = iVar7 >> 3;
                    if (!bVar3 && !(*(int *)((char *)this_00 + iVar2 * 4 + 0x94) > iVar6)) {
                    ((Player *)this_00)->InitSlotFlags(iVar2);
                    if (this_00 ==
                        *(void **)(DAT_0057c670 +
                                   *(int *)(DAT_0057c670 + 0x2ec) * 4 + 0x200)) {
                        UI_Briefing_Printf(DAT_0057c670, -1, 4, -1, -1, 0,
                                           DAT_00582984, DAT_00581ab8, (int *)(iVar1 + 8));
                    }
                }
                }
            }
            param_1 = param_1 + 1;
        } while (param_1 < iVar4);
    }
    return 1;
}
