struct Obj {
    void SetFacadeAndLogoVariant(int a, int b, int c);
    void CS_Enter(); void CS_Leave(); int FindCityIndex();
    void ClearFlags48(int k); void SelectVariant(int k, int v);
};
extern "C" { extern int DAT_0057c670; extern char s_LOGO[]; extern char s_FARBANIM[]; char *String_Find(const char *t, const char *s); }
void Obj::SetFacadeAndLogoVariant(int param_1, int param_2, int param_3)
{
    int iVar1; int iVar2; char *pcVar3; int iVar4; int iVar5; int *piVar6; char *pcVar7; int iVar8;
    ((Obj *)*(int *)(DAT_0057c670 + 0x248))->CS_Enter();
    iVar1 = *(int *)(*(int *)((int)this + 0xfa8) + 0x4c) + *(int *)(param_2 + 0x24) * 0xc;
    iVar4 = ((Obj *)param_3)->FindCityIndex();
    iVar2 = *(int *)(param_3 + 0x1e0);
    iVar5 = *(int *)(iVar1 + 8);
    iVar8 = 0; param_2 = 0;
    if (0 < *(int *)(iVar5 + 0x14)) {
        do {
            piVar6 = (int *)(*(int *)(iVar5 + 0x18) + iVar8);
            pcVar3 = (char *)piVar6[2];
            iVar5 = *piVar6;
            if (*pcVar3 == '\x02') {
                pcVar7 = String_Find(pcVar3 + 4, s_FARBANIM);
                if (pcVar7 != 0) {
                    *(int *)(*(int *)(*(int *)(iVar1 + 8) + 0x18) + 4 + iVar8) = param_1;
                    if (param_1 != 0) ((Obj *)*(int *)(pcVar3 + 0x48))->SelectVariant(iVar5, iVar4);
                    else ((Obj *)*(int *)(pcVar3 + 0x48))->ClearFlags48(iVar5);
                }
                pcVar7 = String_Find(pcVar3 + 4, s_LOGO);
                if (pcVar7 != 0) {
                    *(int *)(*(int *)(*(int *)(iVar1 + 8) + 0x18) + 4 + iVar8) = param_1;
                    if (param_1 != 0) ((Obj *)*(int *)(pcVar3 + 0x48))->SelectVariant(iVar5, iVar2);
                    else ((Obj *)*(int *)(pcVar3 + 0x48))->ClearFlags48(iVar5);
                }
            }
            iVar5 = *(int *)(iVar1 + 8);
            param_2 = param_2 + 1;
            iVar8 = iVar8 + 0xc;
        } while (param_2 < *(int *)(iVar5 + 0x14));
    }
    ((Obj *)*(int *)(DAT_0057c670 + 0x248))->CS_Leave();
}
