extern void *DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
    void RemoveByKey(void *key);
};

struct Game {
    void AbortOrdersTargetingObject(void *object, int mode, int flags);
};

struct Storage {
    void RemoveRecord(void *record);
};

struct Player {
    void DeactivatePlanEntry(void *entry, int mode);
    void RemoveBranch(void *branch);
};

void Player::RemoveBranch(void *branch)
{
    ((Game *)DAT_0057c670)
        ->AbortOrdersTargetingObject(*(void **)((char *)branch + 0x16f0), 1, 0);
    int index = *(int *)((char *)this + 0x140) - 1;
    if (index >= 0) {
        do {
            int *entry = (int *)((IDMap *)((char *)this + 0x12c))
                             ->Lookup(index, 0);
            if (entry[3] == *(int *)((char *)branch + 0x3c))
                DeactivatePlanEntry(entry, 1);
            index--;
        } while (index >= 0);
    }
    ((IDMap *)((char *)this + 0x148))->RemoveByKey(branch);
    int count = *(int *)((char *)this + 0x194);
    int i = 0;
    if (count > 0) {
        do {
            void *storage = (void *)((IDMap *)((char *)this + 0x180))
                               ->Lookup(i, 0);
            ((Storage *)storage)->RemoveRecord(branch);
            i++;
        } while (i < count);
    }
}
