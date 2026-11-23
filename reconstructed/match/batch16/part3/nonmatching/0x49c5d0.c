/* CompanyRanking_SelectLastCompanyButton: clears the company ranking button
   column, selects the requested button and refreshes the active company
   (0x49c5d0). */
extern int DAT_00568a14;
extern int DAT_00568a34;
extern int *DAT_0057c670;
extern int DAT_0057ca40;
extern int DAT_0057ca90;
extern int DAT_0057ca94;
extern int DAT_00582320;

struct Window {
    void GadgetNotify_Button_SetState(int id, int state);
};

struct Game {
    void *GetActiveCompanyById(int id);
    int FindCompanyIndex(int id);
};

struct UI {
    void QueueControlCommand(int command, int arg1, int arg2);
};

extern "C" void CompanyRanking_SelectLastCompanyButton(void *param_1, int param_2)
{
    int *piVar2;
    int iVar1;
    void *ui;

    piVar2 = &DAT_00568a14;
    do {
        ((Window *)param_1)->GadgetNotify_Button_SetState(*piVar2, 0);
        piVar2 = piVar2 + 1;
    } while ((int)piVar2 < (int)&DAT_00568a34);
    ((Window *)param_1)->GadgetNotify_Button_SetState(param_2, 1);
    DAT_0057ca90 = *(int *)(DAT_0057ca94 + 0x1c + DAT_0057ca40 * 4);
    iVar1 = (int)((Game *)(*(int *)((char *)DAT_0057c670 + 0x200 +
                                     *(int *)((char *)DAT_0057c670 + 0x2ec) * 4)))
                     ->GetActiveCompanyById(DAT_0057ca90);
    *(int *)((char *)DAT_0057c670 + 0x98) = iVar1;
    ui = *(void **)((char *)DAT_0057c670 + 0x25c);
    iVar1 = ((Game *)(*(int *)((char *)DAT_0057c670 + 0x200 +
                              *(int *)((char *)DAT_0057c670 + 0x2ec) * 4)))
                ->FindCompanyIndex(*(int *)((char *)DAT_0057c670 + 0x98));
    ((UI *)ui)->QueueControlCommand(-0x18671, 0x23, iVar1);
}
