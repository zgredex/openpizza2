extern char *DAT_0057c670;

/* Game_FindBestCompositeRatedBranch: finds the branch with the best customer
   rating across all players (0x4d8140). */
struct Game {
    void *GetPlayerBySlot(int slot);
};

struct Branch {
    int GetCustomerGroupRating(int group, int flag);
};

struct IDMap {
    void *Lookup(int index, int *unused);
};

extern "C" void *__cdecl Game_FindBestCompositeRatedBranch(int param_1)
{
    int best = -1;
    void *best_branch = 0;
    int slot = 0;
    int i;

    do {
        void *player = ((Game *)DAT_0057c670)->GetPlayerBySlot(slot);

        if (player != 0 && (i = 0, 0 < *(int *)((char *)player + 0x15c))) {
            do {
                Branch *branch = (Branch *)((IDMap *)((char *)player + 0x148))->Lookup(i, 0);

                if (branch != 0) {
                    int rating;

                    if (param_1 == -1) {
                        int sum = 0;
                        int group;

                        for (group = 0; group < 8; group++) {
                            sum = sum + branch->GetCustomerGroupRating(group, 1);
                        }
                        rating = sum / 8;
                    } else {
                        rating = branch->GetCustomerGroupRating(param_1, 1);
                    }
                    if (rating > best) {
                        best = rating;
                        best_branch = branch;
                    }
                }
                i = i + 1;
            } while (i < *(int *)((char *)player + 0x15c));
        }
        slot = slot + 1;
    } while (slot < 6);
    if (best >= 0x1e) {
        return best_branch;
    }
    return 0;
}
