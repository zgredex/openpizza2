/* PC2 byte-match candidate. Build with CL /O2 /GX /TP; see worklog.md and
   verify.py for the exact matcher command. */
void *operator new(unsigned int);
struct List {
    virtual ~List();
    unsigned char data[0x10];
    int count;              /* +0x14 */
    unsigned char pad[4];
    List(int capacity);
    void Add(void *entry);
};
struct UI_ListEntry {
    unsigned char data[0x58];
    UI_ListEntry(char *name, int id);
};
struct SavePage {
    void SetPosition(void *callback, int arg);
    void Text_SetText(int id, char *text);
    void RemoveObjectByKey(int id);
    void Slider_SetRange(int id, int min, int max, int flag);
    void Slider_SetValue(int id, int a, int b);
    void Slider_SetChangeNotify(int id, int flag);
};
extern char *g_text440;         /* 0x582464 */
extern char *g_text441;         /* 0x581ac0 */
extern char *g_defaultSaveName; /* 0x581ab4 */
List *g_saveList;               /* 0x57df84 */
int g_saveIndex;                /* 0x57de74 */
extern void SaveGame_Scan(List *list, int arg);
extern void SubStartMenuA_FillSaveGameRows(void *page, int index);

void __cdecl SubStartMenuA_InitSaveGamePage(void *param_1)
{
    int iVar1;
    int iVar4;
    UI_ListEntry *entry;
    SavePage *page;

    page = (SavePage *)param_1;
    page->SetPosition((void *)0x4cde30, 0);
    page->Text_SetText(0x440, g_text440);
    page->Text_SetText(0x441, g_text441);
    g_saveList = new List(0);
    g_saveIndex = 0;
    SaveGame_Scan(g_saveList, 0);
    iVar1 = g_saveList->count;
    iVar4 = iVar1 - 1;
    if (iVar4 > 0) {
        if (iVar4 < 0xd) {
            int j;
            page->RemoveObjectByKey(0x462);
            j = 0x450;
            if (iVar4 + 0x444 < 0x450) {
                do {
                    page->RemoveObjectByKey(j);
                    page->RemoveObjectByKey(j + 0xf);
                    j = j - 1;
                } while (iVar4 + 0x444 < j);
            }
        } else {
            page->Slider_SetRange(0x462, 0, (iVar4 + -0x3c + iVar4 * 4) * 0x14, 1);
            page->Slider_SetValue(0x462, 0, 0);
            page->Slider_SetChangeNotify(0x462, 1);
        }
    } else {
        iVar4 = 0x450;
        do {
            page->RemoveObjectByKey(iVar4);
            page->RemoveObjectByKey(iVar4 + 0xf);
            iVar4 = iVar4 - 1;
        } while (0x444 < iVar4);
        page->RemoveObjectByKey(0x462);
        g_saveList->Add(new UI_ListEntry(g_defaultSaveName, -1));
    }
    SubStartMenuA_FillSaveGameRows(param_1, g_saveIndex);
}
