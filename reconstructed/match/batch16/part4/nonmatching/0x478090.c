/* Stats_SumFilteredFloats2: sums the twenty-five floats of every record
   matching the filter (0x478090). */
struct IDMap {
    void *Lookup(int index, int *out);
};

class Stats {
public:
    float SumFilteredFloats2(int column, int field, int index);
};

float Stats::SumFilteredFloats2(int param_2, int param_3, int param_4)
{
    int iVar1;
    int iVar2;
    float *pfVar3;
    int iVar4;
    float fVar5;
    float local_8;
    int iVar6;

    iVar1 = *(int *)((char *)this + 0x14f8);
    iVar4 = 0;
    local_8 = 0.0f;
    if (iVar1 <= 0) {
        return local_8;
    }
    do {
        iVar2 = (int)((IDMap *)((char *)this + 0x14e4))->Lookup(iVar4, 0);
        if ((*(int *)(iVar2 + 8) == param_3 || param_3 == -1) &&
            (param_4 == -1 || param_4 == *(int *)(iVar2 + 4))) {
            if (param_2 == -1) {
                fVar5 = local_8;
                pfVar3 = (float *)(iVar2 + 0x78);
                iVar6 = 0x19;
                do {
                    fVar5 = fVar5 + *pfVar3;
                    pfVar3 = pfVar3 + 1;
                    iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
                local_8 = fVar5;
            } else {
                fVar5 = *(float *)(iVar2 + 0x78 + param_2 * 4) + local_8;
                local_8 = fVar5;
            }
        } else {
            fVar5 = local_8;
        }
        iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
    return fVar5;
}
