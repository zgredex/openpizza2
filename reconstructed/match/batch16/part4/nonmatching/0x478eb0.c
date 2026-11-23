/* Stats_ComputeWeightedTotals: computes the eight weighted totals of a
   statistics record (0x478eb0). */
extern int DAT_0057c670;

struct IDMap {
    void *Lookup(int index, int *out);
};

extern "C" void __fastcall Stats_ComputeWeightedTotals(int param_1)
{
    int iVar1;
    int *piVar2;
    int iVar3;
    int *piVar4;

    iVar1 = (int)((IDMap *)(DAT_0057c670 + 4))
               ->Lookup(*(int *)(param_1 + 0x34), 0);
    iVar3 = 0;
    piVar2 = (int *)(param_1 + 0x17dc);
    piVar4 = (int *)(iVar1 + 0x220);
    do {
        iVar1 = piVar4[iVar3 - 8] * *(int *)(param_1 + 0x183c);
        piVar2[iVar3] = iVar1;
        iVar1 = iVar1 + *(int *)(param_1 + 0x1844) * piVar4[iVar3];
        piVar2[iVar3] = iVar1;
        iVar1 = iVar1 + piVar4[iVar3 + 8] * *(int *)(param_1 + 0x1840);
        piVar2[iVar3] = iVar1;
        iVar1 = (piVar4[iVar3 + 0x10] * *(int *)(param_1 + 0x1848) + iVar1) / 100;
        piVar2[iVar3] = iVar1 * 3;
        iVar3 = iVar3 + 1;
        piVar2[iVar3 - 1] = (iVar1 * 9 + *(int *)(param_1 + 0x1a04) +
                             *(int *)(param_1 + 0x19fc)) / 5;
    } while (iVar3 < 8);
}
