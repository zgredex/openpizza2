// Game_FindFreeStaffRecord @ 0x4e1e40 (151 bytes)
// Finds the first unassigned staff record of the requested role.

extern char *DAT_0057c670;

class IDMap {
public:
    char pad[0x14];
    void *Lookup(int index, int *out);
};

class State {
public:
    int Is2DOr2E();
};

class Staff {
public:
    char pad0[0x74];
    int field74;
    char pad1[0xa4 - 0x78];
    int fieldA4;
    char pad2[0xfc - 0xa8];
    int fieldFC;
    char pad3[0x104 - 0x100];
    char field104;
};

struct StaffId {
    int id;
    int type;
};

class Game {
public:
    char pad0[0x1b8];
    IDMap map;
    int count1cc;

    StaffId *FindFreeStaffRecord(int type);
};

StaffId *Game::FindFreeStaffRecord(int type)
{
    int index = 0;
    if (this->count1cc > 0) {
        while (index < this->count1cc) {
            StaffId *record = (StaffId *)this->map.Lookup(index, 0);
            Staff *staff = (Staff *)((IDMap *)(DAT_0057c670 + 0x3c))->Lookup(record->id, 0);
            if (((State *)staff)->Is2DOr2E() == 0 && record->type == type &&
                staff->fieldA4 == -1 && staff->fieldFC != 0 &&
                staff->field104 != 0 && staff->field74 == 0)
                return record;
            index++;
        }
    }
    return 0;
}
