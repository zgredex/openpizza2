/* UI_OpenBriefing: fills the briefing button column for the requested array
   (0x54adc0). */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct Array {
    void *GetRecordByKeyPtr(int key);
};

class UI {
public:
    int OpenBriefing(void *array, int start);
    void AddBriefingButton(void *record, int key, int y);
};

int UI::OpenBriefing(void *param_1, int param_2)
{
    int iVar1;
    int iVar3;
    int iVar4;

    if (*(int *)((char *)this + 0x34) != 0)
        return 0;
    iVar4 = param_2;
    iVar3 = *(int *)((char *)this + 0x20);
    *(void **)((char *)this + 0x34) = param_1;
    *(int *)((char *)this + 0x2c) = param_2;
    param_2 = *(int *)((char *)this + 0x18) + -10;
    if (param_2 < 0) {
        param_2 = 0;
    } else if (8 < param_2) {
        goto LAB_0054ae50;
    }
    do {
        iVar1 = (int)((IDMap *)((char *)this + 4))->Lookup(param_2, 0);
        if ((iVar1 != 0) &&
            (((Array *)param_1)->GetRecordByKeyPtr(iVar4) == 0)) {
            AddBriefingButton((void *)iVar1, iVar4, iVar3);
            *(int *)(iVar1 + 0xc) = iVar3;
            *(int *)(iVar1 + 0x20) = 0;
            *(void **)(iVar1 + 0x18) = this;
            iVar4++;
            iVar3 += *(int *)((char *)this + 0x28);
        }
        param_2++;
    } while (param_2 < 9);
LAB_0054ae50:
    *(int *)((char *)this + 0x30) = 1;
    return 1;
}
