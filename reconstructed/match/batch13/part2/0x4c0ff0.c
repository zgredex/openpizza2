/* StorageMenu_Init (0x4c0ff0). */
extern char *DAT_0057c670;
extern void *DAT_0057d718;
extern int DAT_0057d710;
extern int DAT_00581278;
extern int DAT_00582624;

struct Storage {
    void *FindRecordByField34(int key);
    int FindSubrecordIndex(void *record);
};
struct Gadget {
    void SetText(int id, int text);
};
extern void BranchStoragePanel_Update(void *panel);

void __cdecl StorageMenu_Init(void *panel)
{
    int index = *(int *)(DAT_0057c670 + 0x2ec);
    int key = *(int *)(DAT_0057c670 + 0x218);
    Storage *storage = *(Storage **)(DAT_0057c670 + 0x200 + index * 4);
    DAT_0057d718 = storage->FindRecordByField34(key);
    DAT_0057d710 = storage->FindSubrecordIndex(DAT_0057d718);
    if (*(char *)((int)DAT_0057d718 + 0x3c) != 0)
        ((Gadget *)panel)->SetText(0x541, DAT_00582624);
    else
        ((Gadget *)panel)->SetText(0x541, DAT_00581278);
    BranchStoragePanel_Update(panel);
}
