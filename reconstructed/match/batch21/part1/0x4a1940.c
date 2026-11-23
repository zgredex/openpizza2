/* SaveGame_Scan (0x4a1940). */
extern "C" void *operator_new(unsigned int size);
extern "C" void *DAT_00582894;
extern "C" char *DAT_00580ea0;
extern "C" char STR_00568d04[];
extern "C" char STR_00568d1c[];

struct List {
    void Add(void *entry);
};

struct UI_ListEntry {
    char data[0x58];
    UI_ListEntry(int a, int b);
    ~UI_ListEntry();
};

struct String {
    void SetOwned(char *name);
};

extern "C" void __cdecl SaveGame_ReadHeaderEntry(List *list, char *pattern,
                                                 char *pattern2);

void __cdecl SaveGame_Scan(List *list, int flag)
{
    UI_ListEntry *entry;
    char *name;

    if (flag != 0) {
        entry = new UI_ListEntry((int)DAT_00582894, -1);
        ((String *)entry)->SetOwned(DAT_00580ea0);
        list->Add(entry);
        name = 0;
    } else {
        name = STR_00568d04;
    }
    SaveGame_ReadHeaderEntry(list, name, STR_00568d1c);
}
