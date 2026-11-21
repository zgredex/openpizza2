/* Branch_RemoveAllStaff - 0x4f7b50, 61 bytes */
struct IDMap
{
    int *Lookup(int key, int *fallback);
};

struct Game
{
    int CountObjectsByType(int type);
};

struct Branch
{
    void RemoveStaffMember(void *member, int flag);
    char pad[0x1500];
    IDMap staff;
};

extern "C" void __stdcall Branch_RemoveAllStaff(Branch *branch)
{
    int index = ((Game *)branch)->CountObjectsByType(-1) - 1;

    while (index >= 0)
    {
        int *member = branch->staff.Lookup(index, 0);

        if (*member != 0)
            branch->RemoveStaffMember(member, 0);
        index--;
    }
}
