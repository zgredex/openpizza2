/* Non-matching candidate.
   First difference: offset 0x4, 90 bytes differ.
   original initialises the stack local with the entry push ecx; candidate emits an extra mov to the local slot.
   Kept for evidence; not part of the strict match set. */
extern void *DAT_0057c5e0;
extern void *DAT_0057ba0c;

struct Window {
    void Text_SetText(int id, void *text);
    void AddUniquePair(int id, int value);
};

struct DialogManager {
    void *Loading(void **owner);
    void Set_Field228(void *window);
    void ShowWindowById(void *window);
};

struct Sound {
    void PlaySpeechStatement(int id);
};

struct UI {
    char pad0[0x268];
    void *dialog;
    void ShowMessageDialog(void *text, void *caption);
    void SuspendSimulation();
};

void UI::ShowMessageDialog(void *text, void *caption)
{
    void *local = this;
    if (dialog == 0) {
        SuspendSimulation();
        dialog = ((DialogManager *)DAT_0057c5e0)->Loading(&local);
        ((Window *)dialog)->Text_SetText(0x3e9, caption);
        ((Window *)dialog)->Text_SetText(0x3f9, text);
        ((Window *)dialog)->AddUniquePair(0x3f8, 0xd);
        ((DialogManager *)DAT_0057c5e0)->Set_Field228(dialog);
        ((DialogManager *)DAT_0057c5e0)->ShowWindowById(local);
        ((Sound *)DAT_0057ba0c)->PlaySpeechStatement(0x24);
    }
}
