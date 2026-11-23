/* Branch_RemoveStaffMember (0x47a9d0). */

extern char *DAT_0057c670;

struct Map {
    int LookupLinear(int *key);
};

struct IDMap {
    void *Lookup(int key, int *out);
    void RemoveRecursive(int key);
};

struct Game {
    void *GetRecordByField814();
    void ToggleObjectFlag2();
};

struct Person {
    void ReleaseFromBranch();
};

struct Object {
    void ClearAssignedRecord(void *branch);
    void SetFieldA4Locked(int value);
};

struct Stats {
    void ResetAverages();
};

struct UI {
    void QueueControlCommand(int command, int param, int value);
};

struct Branch {
    char pad0[0x14c4];
    int selected;               /* 0x14c4 */
    char pad1[0x38];
    char map[1];                /* 0x1500 */

    void RemoveStaffMember(int *param_1, int param_2);
};

void Branch::RemoveStaffMember(int *param_1, int param_2)
{
    if (*param_1 == selected)
        selected = 0;
    void *staff = (char *)this + 0x1500;
    int index = ((Map *)staff)->LookupLinear(param_1);

    if (index != -1) {
        int *entry = (int *)((IDMap *)staff)->Lookup(index, 0);
        void *person = (void *)*entry;
        void *record = (void *)((Game *)person)->GetRecordByField814();

        if (*(int *)((char *)record + 0x108) != 1)
            ((Person *)person)->ReleaseFromBranch();
        *(int *)((char *)record + 0x7c) = 0xff;
        if (*(char *)((char *)person + 0x824) == 3 &&
            *(int *)((char *)record + 0xa4) == 4)
            ((Object *)record)->ClearAssignedRecord(this);
        ((IDMap *)staff)->RemoveRecursive(index);
        if (param_2 == 0 &&
            *(void **)(DAT_0057c670 + 0x21c) == record &&
            *(void **)(DAT_0057c670 + 0x25c) != 0)
            ((UI *)*(void **)(DAT_0057c670 + 0x25c))
                ->QueueControlCommand((int)0xfffe79d7, 0x23, 0);
        ((Object *)record)->SetFieldA4Locked(-1);
        *(int *)((char *)record + 0x88) = -1;
        ((Stats *)this)->ResetAverages();
    }
    ((Game *)this)->ToggleObjectFlag2();
}
