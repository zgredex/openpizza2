/* Game_RefreshObjectCategoryBins: counts the category bins of all objects and
   refreshes the object flags when too few players are in the game
   (0x4ffe00). */
struct Game {
    int CountObjectsByType(int type);
    int CountPlayersByByte(int value);
    void MarkAllObjectsDirty(int state);
};

struct IDMap {
    void *Lookup(int index, int *out);
};

extern "C" void Game_RefreshObjectCategoryBins(void *param_1)
{
    int local_20[8];
    int *piVar1;
    int iVar2;
    int iVar4;
    int iVar5;
    unsigned int uVar3;

    piVar1 = local_20;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar1 = 0;
        piVar1 = piVar1 + 1;
    }
    iVar2 = ((Game *)param_1)->CountObjectsByType(0xffffffff);
    iVar5 = 0;
    if (0 < iVar2) {
        do {
            piVar1 = (int *)((IDMap *)((char *)param_1 + 0x1500))
                         ->Lookup(iVar5, 0);
            if (*(char *)(*piVar1 + 0x824) == '\0') {
                uVar3 = piVar1[1];
                iVar4 = 3;
                do {
                    local_20[uVar3 & 7] = local_20[uVar3 & 7] + 1;
                    uVar3 = uVar3 + 1;
                    iVar4 = iVar4 + -1;
                } while (iVar4 != 0);
            }
            iVar5 = iVar5 + 1;
        } while (iVar5 < iVar2);
    }
    piVar1 = local_20;
    iVar5 = 7;
    iVar2 = local_20[0];
    do {
        piVar1 = piVar1 + 1;
        if (iVar2 <= *piVar1) {
            iVar2 = *piVar1;
        }
        iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar5 = ((Game *)param_1)->CountPlayersByByte(5);
    if (iVar5 < iVar2 / 2) {
        ((Game *)param_1)->MarkAllObjectsDirty(2);
    }
}
