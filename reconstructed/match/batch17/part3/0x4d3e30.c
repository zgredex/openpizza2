struct IDMap {
    int unused;
    void *Lookup(int index, int *out);
    int FindIndexByValue(int value);
};

struct Game {
    void *GetPlayerSubmapValue(int player, int submap);
    void *GetRecordByField814();
};

struct Branch {
    void RemoveStaffMember(void *record, int flag);
};

struct Map {
    int *FindRecordByFirstField(int value);
};

struct City {
    void RemovePersonEntry(void *record);
};

struct Person {
    char pad0[0x74];
    int field74;
    int field78;
    char pad1[0x81 - 0x7c];
    char field81;
    char pad2[0x818 - 0x82];
    int field818;
    int field81C;
    int field820;
    void TruncatePathToCurrentStep();
    void RemoveFromStaff();
};

struct GameData {
    char pad0[4];
    IDMap map;
};

extern GameData *DAT_0057c670;
void __cdecl operator delete(void *);

void Person::RemoveFromStaff()
{
    if (*(int *)((char *)this + 0x820) != -1) {
        void *branch = ((Game *)DAT_0057c670)
                           ->GetPlayerSubmapValue(*(int *)((char *)this + 0x81c),
                                                  *(int *)((char *)this + 0x820));
        if (branch != 0) {
            int index = ((IDMap *)branch)->FindIndexByValue((int)this);
            if (index != -1)
                ((Branch *)branch)->RemoveStaffMember(
                    ((IDMap *)((char *)branch + 0x1500))->Lookup(index, 0), 0);
        }
    }
    int key = *(int *)((char *)this + 0x818);
    void *city = ((IDMap *)((char *)DAT_0057c670 + 4))->Lookup(key, 0);
    if (city != 0) {
        int *record = ((Map *)city)->FindRecordByFirstField((int)this);
        if (record != 0) {
            ((City *)city)->RemovePersonEntry(record);
            operator delete(record);
        }
    }
    int *record = (int *)((Game *)this)->GetRecordByField814();
    if (*(int *)((char *)record + 0x78) != 0x23) {
        if (*(int *)((char *)record + 0x74) != 0) {
            *(int *)((char *)record + 0x78) = 0x23;
            *(char *)((char *)record + 0x81) = 1;
        } else {
            *(int *)((char *)record + 0x78) = 0x23;
            ((Person *)record)->TruncatePathToCurrentStep();
        }
    }
}
