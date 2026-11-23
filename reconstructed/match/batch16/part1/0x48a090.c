// Game_CountFilteredObjects2 @ 0x48a090 (153 bytes)
// Counts staff records matching four optional filters.

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
    char pad0[0x30];
    int field30;
    char pad1[0xa4 - 0x34];
    int fieldA4;
    char pad2[0xfc - 0xa8];
    int fieldFC;
    char pad3[0x104 - 0x100];
    char field104;
    char pad4[0x110 - 0x105];
    int field110;
};

class Game {
public:
    char pad0[0x3c];
    IDMap map;
    int count;

    int CountFilteredObjects2(int first, int second, int third, int fourth);
};

int Game::CountFilteredObjects2(int first, int second, int third, int fourth)
{
    int result = 0;
    int index = 0;

    if (this->count > 0) {
        do {
            Staff *staff = (Staff *)this->map.Lookup(index, 0);
            if ((staff->fieldA4 == first || first == -1) && staff->field30 == second &&
                staff->field104 != 0) {
                if (((State *)staff)->Is2DOr2E() == 0 &&
                    (staff->field110 == fourth || fourth == -1) &&
                    (third == 0 || staff->fieldFC == third)) {
                    result++;
                }
            }
            index++;
        } while (index < this->count);
    }
    return result;
}
