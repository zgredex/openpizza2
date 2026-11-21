struct UIManager { void ButtonSetState(int i,int v); void TextSetText(int i,char *t); void SetChildVisibleByID(int i,int v); void RemoveObjectByKey(int i); void ShowChildByID(int i); };
struct IDMap { void *Lookup(int k, int *o); };
extern "C" {
extern int DAT_0057c670; extern int DAT_0057d5c8; extern int DAT_00569354; extern int DAT_0057dfbc;
extern int DAT_00569358; extern float DAT_0057d574; extern char *DAT_005819f8; extern char *DAT_00582e4c;
extern int DAT_0056935c[]; extern int DAT_0056937c[]; extern int DAT_0056939c[]; extern int DAT_0057d578;
extern char s_fmt_percent[]; void __cdecl String_Format(char *b, const char *f, ...);
}
void __cdecl StatisticsBalance_UpdateBranchList(void *panel, int param_2)
{
    int iVar1; int iVar2; int iVar3; int local_3c; int local_38; float *local_34; int local_30; char local_28[36];
    iVar1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
    local_30 = *(int *)(iVar1 + 0x15c);
    if (8 < local_30) local_30 = 8; else param_2 = 0;
    if (DAT_0057d5c8 == 0) local_3c = (DAT_00569354 - DAT_0057dfbc) * 4 + 4;
    else local_3c = DAT_0057d5c8 - 1 + (DAT_00569354 - DAT_0057dfbc) * 4;
    if (DAT_00569358 >= 0) {
        iVar2 = (int)((IDMap *)(iVar1 + 0x148))->Lookup(DAT_00569358, 0);
        if (*(int *)(iVar2 + 0x40) > local_3c) DAT_00569358 = -1;
    }
    ((UIManager *)panel)->ButtonSetState(0x3e9, (DAT_00569358 == -1));
    ((UIManager *)panel)->TextSetText(0x3f8, DAT_005819f8);
    String_Format(local_28, s_fmt_percent, (double)DAT_0057d574);
    ((UIManager *)panel)->TextSetText(0x3fb, local_28);
    ((UIManager *)panel)->SetChildVisibleByID(0x4b2, (DAT_00569358 != -1));
    iVar2 = 0;
    if (0 < local_30) {
        local_38 = param_2; local_34 = (float *)(&DAT_0057d578 + param_2);
        do {
            if (local_38 != DAT_00569358) iVar3 = DAT_0056935c[iVar2];
            else iVar3 = DAT_0056935c[iVar2];
            ((UIManager *)panel)->ButtonSetState(iVar3, (local_38 == DAT_00569358));
            iVar3 = (int)((IDMap *)(iVar1 + 0x148))->Lookup(local_38, 0);
            ((UIManager *)panel)->TextSetText(DAT_0056937c[iVar2], (char *)(iVar3 + 4));
            String_Format(local_28, s_fmt_percent, (double)*local_34);
            ((UIManager *)panel)->TextSetText(DAT_0056939c[iVar2], local_28);
            if (*(int *)(iVar3 + 0x40) > local_3c) {
                ((UIManager *)panel)->RemoveObjectByKey(DAT_0056935c[iVar2]);
                ((UIManager *)panel)->TextSetText(DAT_0056939c[iVar2], DAT_00582e4c);
            } else ((UIManager *)panel)->ShowChildByID(DAT_0056935c[iVar2]);
            iVar2++; local_38++; local_34++;
        } while (iVar2 < local_30);
    }
}
