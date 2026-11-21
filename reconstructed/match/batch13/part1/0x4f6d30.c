/* Game_CompanyManager_Construct (0x4f6d30). */
extern char DAT_0055c618[];
struct Renderer {
    void *CreateChild();
};
extern Renderer *DAT_0057c5c8;
extern "C" __declspec(dllimport) void __stdcall
    InitializeCriticalSection(void *section);
extern void CRT_BeginThread(void *start, void *arg, int parameter);

struct Slot {
    int field0;             /* 0x00 */
    int field4;             /* 0x04 */
    char pad[0x160];
};
struct CompanyManager {
    void *vtable;           /* 0x00 */
    char pad0[4];
    int field08;            /* 0x08 */
    int field0c;            /* 0x0c */
    int field10;            /* 0x10 */
    char pad1[4];
    int field18;            /* 0x18 */
    void *child;            /* 0x1c */
    char lock[0x114 - 0x20];
    Slot slots[6];          /* 0x114 */

    CompanyManager *Construct();
};
extern char DAT_004f6da0[];

CompanyManager *__fastcall Game_CompanyManager_Construct(CompanyManager *manager)
{
    int index;
    Slot *slot;

    manager->vtable = DAT_0055c618;
    manager->field08 = 1;
    manager->field18 = 0;
    manager->field10 = -1;
    *(int *)((char *)manager + 0x38) = 0;
    manager->field0c = 0;
    manager->child = DAT_0057c5c8->CreateChild();
    InitializeCriticalSection(manager->lock);
    slot = manager->slots;
    index = 6;
    do {
        slot->field4 = 0;
        slot->field0 = 0;
        slot = (Slot *)((char *)slot + 0x168);
        index--;
    } while (index != 0);
    CRT_BeginThread(DAT_004f6da0, 0, (int)manager);
    return manager;
}
