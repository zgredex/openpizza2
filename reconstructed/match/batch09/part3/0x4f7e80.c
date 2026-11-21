/* Company_HireFreeGuard: claims a free guard slot and registers it with the
   company (0x4f7e80). */
extern "C" int DAT_0057c670;

struct Game {
    int CountFreeSlots(int type);
    int FindFreeObjectByType(int type);
};

struct Company {
    void AddStaffMember(int staffId, int type);
};

int __stdcall Company_HireFreeGuard(void *company)
{
    int guard;

    if (((Game *)DAT_0057c670)->CountFreeSlots(0x17) == 0)
        return 0;
    guard = ((Game *)DAT_0057c670)->FindFreeObjectByType(0x17);
    if (guard == 0)
        return 0;
    ((Company *)company)->AddStaffMember(*(int *)((char *)guard + 0x164), 0x17);
    return 1;
}
