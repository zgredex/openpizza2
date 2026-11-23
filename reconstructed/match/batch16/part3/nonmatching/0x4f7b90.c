/* AI_ComputePlanScores: fills the plan score array and returns the number of
   evaluated entries (0x4f7b90). */
extern int DAT_0057c670;
extern "C" void *memset(void *dest, int value, unsigned int count);

struct Stats {
    float SumFilteredFloats(int filter, int column, int index);
    float SumFilteredFloats2(int filter, int column, int index);
};

extern "C" int AI_ComputePlanScores(int param_1, int *param_2, int *param_3,
                                    int param_4)
{
    unsigned short uVar1;
    int *piVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;

    piVar2 = param_2;
    uVar1 = *(unsigned short *)(*(int *)(DAT_0057c670 + 0x94) + 10);
    iVar5 = 0;
    *param_2 = 0;
    memset(param_3, 0, param_4 * 4);
    iVar6 = uVar1 - 1;
    iVar3 = *(int *)(param_1 + 0x40);
    if (-1 < iVar6) {
        param_2 = param_3;
        while (iVar3 <= iVar6) {
            int first = (int)((Stats *)param_1)->SumFilteredFloats(-1, -1, iVar6);
            int second = (int)((Stats *)param_1)->SumFilteredFloats2(-1, -1, iVar6);

            iVar4 = first - second;
            *param_2 = iVar4;
            param_2 = param_2 + 1;
            iVar5 = iVar5 + 1;
            *piVar2 = *piVar2 + iVar4;
            if (iVar5 == param_4)
                return iVar5;
            iVar6 = iVar6 + -1;
            if (iVar6 < 0)
                return iVar5;
        }
    }
    return iVar5;
}
