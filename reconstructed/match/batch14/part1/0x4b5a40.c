/* BranchScreen_SelectBranchRecord (0x4b5a40): selects the branch record for
   the current city and updates the branch-information widgets. */
extern int DAT_0057d6a8;
extern int DAT_0057d6ac;
extern int DAT_0057c670;
extern int DAT_0057ba0c;

struct IDMap {
    int Lookup(int key, int *out);
};

struct Sound {
    void SelectCurrentTrack();
};

struct Window_GadgetNotify_Text {
    void SetText(int id, char *text);
};

struct UI {
    void QueueControlCommand(int message, int wparam, int lparam);
};

struct Game {
    char pad[0x9c];
    int selectedBranch;
    char pad2[0x264 - 0xa0];
    UI *control;
};

struct BranchRecord {
    char pad[4];
    char name[0x3c - 4];
    int cityId;
};

void __cdecl BranchScreen_SelectBranchRecord(void *param_1, char param_2)
{
    BranchRecord *record;

    record = (BranchRecord *)((IDMap *)(DAT_0057d6ac + 0x148))
                 ->Lookup(DAT_0057d6a8, 0);
    ((Game *)DAT_0057c670)->selectedBranch = (int)record;
    ((Sound *)DAT_0057ba0c)->SelectCurrentTrack();
    DAT_0057d6a8 = record->cityId;
    ((Window_GadgetNotify_Text *)param_1)->SetText(0x40f, record->name);
    if (param_2 != '\0') {
        ((Game *)DAT_0057c670)->control->QueueControlCommand(
            -0x1864e, 0x23, record->cityId);
    }
}
