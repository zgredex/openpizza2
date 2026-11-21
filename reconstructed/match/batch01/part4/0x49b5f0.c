/* PC2 byte-match candidate. Build with CL /O2 /GX /TP; see worklog.md and
   verify.py for the exact matcher command. */
void *operator new(unsigned int);
struct IDMap {
    int Lookup(int key, int *out);
};
struct List {
    virtual ~List();
    unsigned char data[0x18];
    List(int capacity);
    void Add(void *entry);
};
struct UI_ListEntry {
    unsigned char data[0x58];
    UI_ListEntry(char *name, int id);
};
extern int *g_game;
List *g_menuList;

int __cdecl Menu_BuildUnassignedMenuList(void)
{
    int iVar1;
    int iVar2;
    int i;
    int count;
    int entry;

    count = 0;
    iVar1 = *(int *)((int)g_game + 0x200 + *(int *)((int)g_game + 0x2ec) * 4);
    iVar2 = *(int *)(iVar1 + 0x124);
    if (iVar2 == 0)
        return -1;
    g_menuList = new List(0);
    if (0 < iVar2) {
        for (i = 0; i < iVar2; i++) {
            entry = ((IDMap *)(iVar1 + 0x110))->Lookup(i, 0);
            if (*(char *)(entry + 0x1dc) == 0 && 0 < *(int *)(entry + 0x1d8)) {
                g_menuList->Add(new UI_ListEntry((char *)(entry + 4), i));
                count = count + 1;
            }
        }
        if (count != 0)
            goto done;
    }
    if (g_menuList != 0)
        delete g_menuList;
done:
    return count;
}
