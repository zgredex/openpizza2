// Person_AssignBranchStaffRole @ 0x50b5e0 (156 bytes)
// Assigns a person to a branch staff-role slot and selects the matching
// UI role state.

class Object {
public:
    void SetDestinationAndTarget(int mode, void *target);
    void SetFieldA4Locked(int value);
};

class UI {
public:
    void SetChildState(int state);
};

class Person {
public:
    char pad0[0x8c];
    int field8C;
    char pad1[0x98 - 0x90];
    int field98;
    char pad2[0x108 - 0x9c];
    int field108;
    int field10C;

    void AssignBranchStaffRole(int branch, int role, int value, char flag);
};

void Person::AssignBranchStaffRole(int branch, int role, int value, char flag)
{
    if (flag)
        field108 = 2;
    *(char *)(branch + 0x1880 + role) = 1;
    ((Object *)this)->SetDestinationAndTarget(
        1, *(void **)(branch + 0x16f0));
    ((Object *)this)->SetFieldA4Locked(0xc);
    field98 = 1;
    field8C = value;
    switch (role) {
    case 0:
        ((UI *)this)->SetChildState(0x17);
        break;
    case 1:
        ((UI *)this)->SetChildState(0x18);
        break;
    case 2:
        ((UI *)this)->SetChildState(0x19);
        break;
    }
    field10C = role;
}
