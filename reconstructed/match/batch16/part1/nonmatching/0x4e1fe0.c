// AI_FindTargetWithMinA8 @ 0x4e1fe0 (154 bytes)
// Finds the unassigned staff record with the smallest field A8.

extern char *DAT_0057c670;

class IDMap {
public:
    char pad[0x14];
    void *Lookup(int index, int *out);
};

class Staff {
public:
    char pad0[0xa4];
    int fieldA4;
    int fieldA8;
    char pad1[0xfc - 0xac];
    int fieldFC;
    char pad2[0x104 - 0x100];
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
    int count;

    StaffId *FindTargetWithMinA8(int type);
};

StaffId *Game::FindTargetWithMinA8(int type)
{
    int index;
    StaffId *best;
    int minimum;

    minimum = 0x65;
    best = 0;
    index = 0;
    if (this->count > 0) {
        do {
            StaffId *record = (StaffId *)this->map.Lookup(index, 0);
            Staff *staff = (Staff *)((IDMap *)(DAT_0057c670 + 0x3c))->Lookup(record->id, 0);
            if (record->type == type && staff->fieldA4 == -1 && staff->fieldFC != 0 &&
                staff->field104 != 0 && staff->fieldA8 < minimum) {
                minimum = staff->fieldA8;
                best = record;
            }
            index++;
        } while (index < this->count);
    }
    return best;
}
