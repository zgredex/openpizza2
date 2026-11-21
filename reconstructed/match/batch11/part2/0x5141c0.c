/* StaffList_AddId: appends an employee id to the first free staff slot
   (0x5141c0). */
struct StaffListHelper {
    int FindPair(int id);
};

struct StaffList {
    char pad[0x60];
    int entries[0x14][3];

    int AddId(int id);
};

int StaffList::AddId(int id)
{
    int index;

    if (((StaffListHelper *)this)->FindPair(id) != -1)
        return 0;
    for (index = 0; index < 0x14; index++) {
        if (entries[index][0] == 0) {
            *(int *)((char *)this + index * 0xc + 100) = id;
            *(int *)((char *)this + (index * 3 + 0x18) * 4) = 1;
            *(int *)((char *)this + index * 0xc + 0x68) = 0;
            return 1;
        }
    }
    return 0;
}
