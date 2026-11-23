struct IDMap {
    int unused;
    void *Lookup(int index, int *out);
    void RemoveByKey(int key);
};

struct Person {
    char pad0[0x74];
    int field74;
    char pad1[0x81 - 0x78];
    char field81;
    char pad2[0xcc - 0x82];
    int fieldCC;
    char pad3[0x10c - 0xd0];
    int field10C;
    int field110;
};

struct Object {
    void SetBuildingRecordForAllCompanies(int type, int value);
    void SetFieldA4Locked(int value);
    void SetDestinationAndTarget(int type, int target);
};

struct Company {
    char pad0[0x1b8];
    IDMap staffMap;
    char pad1[0x10];
    int staffCount;
    void RemoveStaffMember(int id);
};

struct GameData {
    char pad[0x3c];
    IDMap personMap;
};

extern GameData *DAT_0057c670;

void Company::RemoveStaffMember(int id)
{
    Person *person = (Person *)((IDMap *)((char *)DAT_0057c670 + 0x3c))->Lookup(id, 0);
    int *record = 0;
    if (person != 0) {
        *(int *)((char *)person + 0x110) = -1;
        ((Object *)person)->SetBuildingRecordForAllCompanies(0x17, 0);
        ((Object *)person)->SetFieldA4Locked(-1);
        *(int *)((char *)person + 0x10c) = -1;
        if (*(int *)((char *)person + 0x74) != 0)
            *(char *)((char *)person + 0x81) = 1;
        else
            ((Object *)person)->SetDestinationAndTarget(
                5, *(int *)((char *)person + 0xcc));
        int count = *(int *)((char *)this + 0x1cc);
        int i = 0;
        if (0 < count) {
            do {
                record = (int *)((IDMap *)((char *)this + 0x1b8))->Lookup(i, 0);
                if (*record == id)
                    break;
                i++;
            } while (i < count);
        }
        ((IDMap *)((char *)this + 0x1b8))->RemoveByKey((int)record);
    }
}
