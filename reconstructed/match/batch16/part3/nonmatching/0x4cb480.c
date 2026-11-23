/* FreePlaySetup_RefreshPlayerProfiles: shows or hides the free-play
   player-profile slots (0x4cb480). */
extern int DAT_0057bdd4;
extern int DAT_0057c194;

extern "C" void FreePlaySetup_SetOpponentSlotEnabled(void *ui, int slot,
                                                     unsigned enabled);

struct UI {
    void SetChildVisibleByID(int id, unsigned visible);
};

extern "C" void FreePlaySetup_RefreshPlayerProfiles(void *param_1)
{
    unsigned uVar1;
    unsigned enabled;
    int *piVar2;
    int iVar3;
    int iVar4;

    iVar3 = 0;
    iVar4 = 1;
    piVar2 = &DAT_0057bdd4;
    do {
        if (*piVar2 != 0) {
            iVar3 = iVar3 + 1;
            enabled = 1;
        } else {
            enabled = 0;
        }
        FreePlaySetup_SetOpponentSlotEnabled(param_1, iVar4, enabled);
        piVar2 = piVar2 + 0x30;
        iVar4 = iVar4 + 1;
    } while ((int)piVar2 < (int)&DAT_0057c194);
    uVar1 = (unsigned)(0 < iVar3);
    ((UI *)param_1)->SetChildVisibleByID(0x4a3, uVar1);
    ((UI *)param_1)->SetChildVisibleByID(0x439, uVar1);
    ((UI *)param_1)->SetChildVisibleByID(0x48b, uVar1);
    ((UI *)param_1)->SetChildVisibleByID(0x48c, uVar1);
    ((UI *)param_1)->SetChildVisibleByID(0x48d, uVar1);
    iVar3 = 0x482;
    do {
        ((UI *)param_1)->SetChildVisibleByID(iVar3, uVar1);
        iVar3 = iVar3 + 1;
    } while (iVar3 < 0x48b);
}
