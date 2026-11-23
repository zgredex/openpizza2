/* Game_ToggleObjectFlag2: refreshes the map object flags from the object
   counts of the current game (0x47ec70). */
extern int DAT_0057c670;

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    int CountObjectsByType(int type);
};

struct Map {
    void SetObjectFlags(void *object, int flags);
    void ClearObjectFlags(void *object, int flags);
};

extern "C" void __fastcall Game_ToggleObjectFlag2(void *param_1)
{
    void *this_00;
    void *pvVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int all;

    this_00 = *(void **)((char *)param_1 + 0x16f0);
    iVar2 = (int)((IDMap *)(DAT_0057c670 + 4))
               ->Lookup(*(int *)((char *)this_00 + 0x28), 0);
    pvVar1 = *(void **)(iVar2 + 0xfa8);
    all = 1;
    iVar2 = ((Game *)param_1)->CountObjectsByType(0);
    if (iVar2 != 0) {
        ((Map *)this_00)->ClearObjectFlags(pvVar1, 2);
    } else {
        ((Map *)this_00)->SetObjectFlags(pvVar1, 2);
        all = 0;
    }
    iVar3 = ((Game *)param_1)->CountObjectsByType(2);
    if (iVar3 != 0) {
        ((Map *)this_00)->ClearObjectFlags(pvVar1, 4);
    } else {
        ((Map *)this_00)->SetObjectFlags(pvVar1, 4);
        all = 0;
    }
    iVar4 = ((Game *)param_1)->CountObjectsByType(3);
    if (iVar4 != 0) {
        ((Map *)this_00)->ClearObjectFlags(pvVar1, 8);
        if (all != 0) {
            *(unsigned int *)((char *)param_1 + 0x28) =
                *(unsigned int *)((char *)param_1 + 0x28) & 0xfd;
            return;
        }
    } else {
        ((Map *)this_00)->SetObjectFlags(pvVar1, 8);
    }
    *(unsigned int *)((char *)param_1 + 0x28) =
        *(unsigned int *)((char *)param_1 + 0x28) | 2;
}
