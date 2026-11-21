/* FreePlaySubmenu_InitSaveGamePage (0x4ce450). */
struct List {
    char pad[0x14];
    int count;
    char pad2[4];
    List(int value);
    void Add(void *item);
};

struct UIListEntry {
    char pad[0x58];
    UIListEntry(char *text, int value);
};

struct UI {
    void SetPosition(void *object, int value);
    void TextSetText(int id, char *text);
    void RemoveObjectByKey(int id);
    void Slider_SetRange(int id, int a, int b, int c);
    void Slider_SetValue(int id, int a, int b);
    void Slider_SetChangeNotify(int id, int value);
};

extern "C" {
extern char *DAT_00582464;
extern char *DAT_00581ac0;
extern List *DAT_0057df88;
extern int DAT_0057df8c;
extern char *DAT_00581ab4;
void SaveGame_Scan(void *list, int flag);
void FillSaveGameRows(void *panel, int index);
}

void FreePlaySubmenu_InitSaveGamePage(UI *panel)
{
    panel->SetPosition((void *)0x4ce3b0, 0);
    panel->TextSetText(0x440, DAT_00582464);
    panel->TextSetText(0x441, DAT_00581ac0);
    DAT_0057df88 = new List(0);
    DAT_0057df8c = 0;
    SaveGame_Scan(DAT_0057df88, 0);
    int n = DAT_0057df88->count - 1;
    if (0 < n) {
        if (n < 0x13) {
            panel->RemoveObjectByKey(0x462);
            for (int i = 0x7e2; i > n + 0x7d0; i--) {
                panel->RemoveObjectByKey(i);
                panel->RemoveObjectByKey(i + 0x64);
            }
        } else {
            panel->Slider_SetRange(0x462, 0, (n * 5 - 0x5a) * 5 * 4, 1);
            panel->Slider_SetValue(0x462, 0, 0);
            panel->Slider_SetChangeNotify(0x462, 1);
        }
    } else {
        for (int i = 0x7e2; i > 0x7d0; i--) {
            panel->RemoveObjectByKey(i);
            panel->RemoveObjectByKey(i + 0x64);
        }
        panel->RemoveObjectByKey(0x462);
        DAT_0057df88->Add(new UIListEntry(DAT_00581ab4, -1));
    }
    FillSaveGameRows(panel, DAT_0057df8c);
}
