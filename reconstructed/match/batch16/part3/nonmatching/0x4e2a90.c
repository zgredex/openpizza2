/* AI_GetTopActionIndices: counts the positive action counters per record and
   returns the two most frequent action indices (0x4e2a90). */
extern "C" void CRT_QSort(void *base, int count, int size, void *compare);
extern "C" int CompareActionIndices(const void *a, const void *b);

struct IDMap {
    void *Lookup(int index, int *out);
};

class AI {
public:
    void GetTopActionIndices(int *first, int *second);
};

void AI::GetTopActionIndices(int *param_1, int *param_2)
{
    int local_2b0[172];
    int iVar1;
    int iVar2;
    int *piVar3;
    int *piVar4;

    iVar1 = 0;
    piVar4 = local_2b0 + 1;
    do {
        piVar4[-1] = iVar1;
        *piVar4 = 0;
        iVar1 = iVar1 + 1;
        piVar4 = piVar4 + 2;
    } while (iVar1 < 0x56);
    iVar1 = 0;
    if (0 < *(int *)((char *)this + 0x124)) {
        do {
            iVar2 = (int)((IDMap *)((char *)this + 0x110))->Lookup(iVar1, 0);
            piVar4 = local_2b0 + 3;
            piVar3 = (int *)(iVar2 + 0x68);
            iVar2 = 0x55;
            do {
                if (0 < *piVar3) {
                    *piVar4 = *piVar4 + 1;
                }
                piVar3 = piVar3 + 1;
                piVar4 = piVar4 + 2;
                iVar2 = iVar2 + -1;
            } while (iVar2 != 0);
            iVar1 = iVar1 + 1;
        } while (iVar1 < *(int *)((char *)this + 0x124));
    }
    CRT_QSort(local_2b0, 0x56, 8, (void *)CompareActionIndices);
    *param_1 = local_2b0[0];
    *param_2 = local_2b0[2];
}
