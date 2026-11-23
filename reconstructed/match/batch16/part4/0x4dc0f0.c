/* Company_PlaceScenarioBranches: creates the scenario-assigned branches of a
   company (0x4dc0f0). */
extern int DAT_0057c670;
extern int DAT_0057bb30;
extern char DAT_0057bb34;
extern char DAT_0057bb20;
extern char DAT_0057bb3d;

struct Company {
    void EnsureRequiredBranch(void *company, void *scenario, int branch);
    void OpenStartingBranch(int branch, int type, int index, void *value);
};

class ScenarioCompany {
public:
    void PlaceScenarioBranches(void *param_1);
};

void ScenarioCompany::PlaceScenarioBranches(void *param_1)
{
    Company *this_00;
    int iVar1;
    int iVar2;
    int *puVar3;

    this_00 = (Company *)*(void **)(DAT_0057c670 + 0x90);
    iVar1 = *(int *)((char *)param_1 + 0x4c);
    if ((0 < DAT_0057bb30) && ((char)DAT_0057bb34 != '\0')) {
        this_00->EnsureRequiredBranch(param_1, this, DAT_0057bb30);
    }
    if (DAT_0057bb20 != '\0') {
        if (DAT_0057bb3d != '\0') {
            this_00->OpenStartingBranch(iVar1, 0, 0, (void *)0xffffffff);
        }
        return;
    }
    iVar2 = 0;
    if (0 < *(int *)((char *)this + 0x364)) {
        puVar3 = (int *)((char *)this + 0x370);
        do {
            if (puVar3[-2] == iVar1) {
                this_00->OpenStartingBranch(iVar1, puVar3[-1], puVar3[1],
                                            (void *)*puVar3);
            }
            iVar2 = iVar2 + 1;
            puVar3 = puVar3 + 4;
        } while (iVar2 < *(int *)((char *)this + 0x364));
    }
}
