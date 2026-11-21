/* Player_ReleaseAssignmentForObject (0x4e2dc0). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
struct Company {
    void RemoveStaffMember(int id);
};
struct Player {
    char pad00[0x1b8];
    struct IDMap map1b8;
    int count1cc;

    void ReleaseAssignmentForObject(void *object);
};
extern "C" char *DAT_0057c670;

void Player::ReleaseAssignmentForObject(void *object)
{
    int *entry = (int *)this;
    int index = 0;

    for (; index < count1cc; index = index + 1) {
        entry = (int *)map1b8.Lookup(index, 0);
        if (((struct IDMap *)(DAT_0057c670 + 0x3c))->Lookup(*entry, 0) ==
            object) {
            break;
        }
    }
    if (index != count1cc) {
        ((struct Company *)this)->RemoveStaffMember(*entry);
    }
}
