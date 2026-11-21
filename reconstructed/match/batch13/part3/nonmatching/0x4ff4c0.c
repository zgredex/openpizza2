/* AI_HireBranchWorker (0x4ff4c0). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
struct Person {
    void SendToBranchForAction(int target, int action);
};
struct Game {
    int *FindFreeStaffRecord(int role);
    unsigned char CanAffordWithCurrency(int currency, float amount,
                                        unsigned char flag, int limit);
};
extern "C" char *DAT_0057c670;

extern "C" int __stdcall AI_HireBranchWorker(struct Game *game, int target)
{
    int *staff = game->FindFreeStaffRecord(0x1d);
    struct Person *person;

    if (staff == 0) {
        return 0;
    }
    person = (struct Person *)((struct IDMap *)(DAT_0057c670 + 0x3c))->Lookup(
        *staff, 0);
    if (person == 0) {
        return 0;
    }
    if (game->CanAffordWithCurrency(0x17, 5000.0f, 1, -1) == 0) {
        return 0;
    }
    person->SendToBranchForAction(target, 0x10);
    return 1;
}
