/* UI_ShiftRowData: shifts one row of the player schedule and refreshes the
   dependent array entries (0x4fc990). */
extern int DAT_0057c670;

extern "C" void __stdcall Game_MarkObjectsDirtyForState(void *game, int state);
extern "C" void __fastcall Array_ClearStride34(int array);

struct Game {
    void *GetPlayerBySlot(int slot);
};

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Array {
    int FindIndexByPtr(int record);
};

class UI {
public:
    void ShiftRowData(void *array, int forced);
};

void UI::ShiftRowData(void *param_1, int param_2)
{
    int iVar1;
    void *this_00;
    int iVar2;
    int *puVar3;
    int iVar4;

    if ((param_2 != 0) ||
        (1 < (int)((unsigned int)*(unsigned short *)(
                       *(int *)(DAT_0057c670 + 0x94) + 10) -
                   *(int *)((char *)param_1 + 0x40)))) {
        iVar1 = (int)((Game *)DAT_0057c670)
                    ->GetPlayerBySlot(*(int *)((char *)param_1 + 0x30));
        iVar1 = *(int *)(iVar1 + 0x4c);
        iVar2 = *(int *)((char *)param_1 + 0x34);
        this_00 = ((IDMap *)(DAT_0057c670 + 4))->Lookup(iVar2, 0);
        iVar4 = 3;
        iVar1 = iVar1 * 0x168 + iVar2 * 0x10;
        puVar3 = (int *)((char *)this + iVar1 + 0x144);
        do {
            *puVar3 = puVar3[-1];
            puVar3 = puVar3 + -1;
            iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        iVar2 = ((Array *)this_00)
                    ->FindIndexByPtr(*(int *)((char *)param_1 + 0x16f0));
        *(int *)((char *)this + iVar1 + 0x138) = iVar2;
        Game_MarkObjectsDirtyForState(param_1, 6);
        Array_ClearStride34((int)param_1);
    }
}
