/* PC2 byte-match candidate. Build with CL /O2 /GX /TP; see worklog.md and
   verify.py for the exact matcher command. */
struct IDMap {
    int Lookup(int key, int *out);
};
struct Map {
    void *GetCell(int x, int y);
    void SetTileFieldWithDefault(void *cell, int value, int flag);
};
struct ConstructionOrder {
    unsigned char data[0x24];
    ConstructionOrder(int a, int b);
};
struct List {
    void Add(void *object);
    void Reset(void);
};
struct GameObj {
    void ClearPendingMapObjects(void);
    void GetSizeName(int value, int size);
    void ApplyBuildingStyleVariant(int style);
};
struct MapThis {
    void CommitPendingObjectEdits(int *ctx, char force);
    void BuildTerrainGrid(void *ctx);
    void FreeValuesAndDestroy(void *values);
};
extern GameObj *g_game;         /* 0x57c670 */
extern "C" void __cdecl Mem_Free(void *block);

void MapThis::CommitPendingObjectEdits(int *ctx, char force)
{
    int iVar1;
    int iVar2;
    int iVar6;
    int *piVar3;
    int iVar4;
    int iVar5;
    IDMap *mgr;
    void *map;
    void *cell;

    if (ctx != 0 && ctx[3] != 0) {
        iVar1 = *(int *)(*ctx + 0x24);
        ((GameObj *)*ctx)->ClearPendingMapObjects();
        mgr = (IDMap *)ctx[3];
        map = *(void **)(*ctx + 0x14e0);
        iVar2 = *(int *)((char *)mgr + 0x14);
        for (iVar6 = 0; iVar6 < iVar2; iVar6++) {
            piVar3 = (int *)mgr->Lookup(iVar6, 0);
            if (force != '\0' || piVar3[7] != 0) {
                cell = ((Map *)map)->GetCell(
                    (int)(short)piVar3[5], (int)*(short *)((char *)piVar3 + 0x16));
                ((Map *)map)->SetTileFieldWithDefault(
                    cell, *piVar3, *(unsigned char *)((char *)piVar3 + 0x18) - 1);
                if (piVar3[8] != 0 && piVar3[3] != -1) {
                    ((IDMap *)((char *)g_game + 0x74))->Lookup(piVar3[3], 0);
                    iVar5 = (int)new ConstructionOrder(piVar3[3], piVar3[4]);
                    *(int *)(iVar5 + 0x18) = (int)(short)piVar3[5];
                    *(int *)(iVar5 + 0x1c) = (int)*(short *)((char *)piVar3 + 0x16);
                    *(int *)(iVar5 + 0x20) = **(int **)((char *)cell + 8);
                    ((List *)(*ctx + 0x16f8))->Add((void *)iVar5);
                }
            }
            Mem_Free(piVar3);
        }
        ((List *)mgr)->Reset();
        if (ctx[7] == 0) {
            *(int *)(*ctx + 0x19fc) = iVar1;
            *(int *)(*ctx + 0x1a04) = iVar1;
            *(int *)(*ctx + 0x1a00) = ctx[9];
            ((GameObj *)*ctx)->GetSizeName(iVar1, *(int *)(*ctx + 0x1a00));
            ((GameObj *)*ctx)->ApplyBuildingStyleVariant(*(int *)(*ctx + 0x1a04));
        }
        BuildTerrainGrid(ctx);
        FreeValuesAndDestroy((void *)ctx[3]);
        ctx[3] = 0;
        *(int *)(*ctx + 0x1718) = 0;
    }
}
