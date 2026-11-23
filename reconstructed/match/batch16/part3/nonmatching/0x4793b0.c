/* Stats_ComputeOccupancyPercent: counts the usable and empty cells of the
   fifty-by-fifty occupancy grid (0x4793b0). */
extern float DAT_0055c320;

extern "C" void Clamp_0_100(int *value);

class Stats {
public:
    int ComputeOccupancyPercent(short *grid);
};

int Stats::ComputeOccupancyPercent(short *param_1)
{
    short sVar1;
    short *psVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;

    iVar4 = 0;
    iVar3 = 0;
    psVar2 = param_1 + 2;
    iVar6 = 0x50;
    do {
        iVar5 = 0x50;
        do {
            sVar1 = *psVar2;
            if ((sVar1 < -3) || ((-1 < sVar1 && (sVar1 != 9)))) {
                if (sVar1 == 0) {
                    iVar3 = iVar3 + 1;
                }
                iVar4 = iVar4 + 1;
            }
            psVar2 = psVar2 + 4;
            iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (iVar3 < 1) {
        *(int *)((char *)this + 0x1858) = 100;
    } else {
        *(int *)((char *)this + 0x1858) =
            (int)((float)iVar4 / iVar3 * DAT_0055c320);
    }
    Clamp_0_100((int *)((char *)this + 0x1858));
    return iVar4;
}
