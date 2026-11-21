/* Game_ShowFindPersonPrompt: shows the find-person amount entry dialog
   (0x48bae0). */
extern int DAT_00582420;
extern int DAT_00582ab4;

struct UI {
    void ShowAmountEntryDialog(int a, int b, int c, int d, int *value,
                               int e, int f, int g);
};

void __fastcall Game_ShowFindPersonPrompt(UI *self)
{
    int value[16];
    int i;

    for (i = 0; i < 16; i++)
        value[i] = 0;
    self->ShowAmountEntryDialog(1, (int)0xfffe79e6, DAT_00582ab4,
                                DAT_00582420, value, 0, 0, 0);
}
