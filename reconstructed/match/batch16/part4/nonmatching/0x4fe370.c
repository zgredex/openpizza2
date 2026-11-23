/* Company_AssignStaffToBranch: assigns a free staff member to a branch
   building (0x4fe370). */
extern int DAT_0057c670;

struct Game {
    int CountObjectsForOwner(int owner, int type);
    int *FindAssignedSubrecord(int owner, int index);
};

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Person {
    void SetRouteToBuilding(int building);
};

struct Company {
    void RemoveStaffMember(int member);
};

struct Object {
    void SetFieldA4Locked(int value);
};

extern "C" int __stdcall Company_AssignStaffToBranch(void *param_1, int param_2)
{
    int iVar1;
    int *piVar2;
    int *this_00;

    iVar1 = ((Game *)param_1)->CountObjectsForOwner(param_2, 0x17);
    if (iVar1 == 0) {
        return 0;
    }
    piVar2 = ((Game *)param_1)->FindAssignedSubrecord(param_2, 0);
    if (piVar2 == 0) {
        piVar2 = ((Game *)param_1)->FindAssignedSubrecord(param_2, 1);
        if (piVar2 == 0) {
            return 0;
        }
    }
    this_00 = (int *)((IDMap *)(DAT_0057c670 + 0x3c))->Lookup(*piVar2, 0);
    if (*(int *)((char *)this_00 + 0x74) != 0) {
        *(char *)((char *)this_00 + 0x81) = 1;
    } else {
        if (*(int *)((char *)param_1 + 0x1d8) != 0) {
            ((Person *)this_00)
                ->SetRouteToBuilding(*(int *)((char *)param_1 + 0x1d8));
        } else {
            ((Company *)param_1)->RemoveStaffMember(*piVar2);
        }
    }
    ((Object *)this_00)->SetFieldA4Locked(-1);
    *(int *)((char *)this_00 + 0x10c) = -1;
    return 1;
}
