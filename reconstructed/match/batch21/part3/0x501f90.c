// Game_GetBestBuildingRatingBand @ 0x501f90 (157 bytes)
// Returns the best customer-group rating band over the current city's
// branch list.

extern char *DAT_0057c670;

struct IDMapHelper {
    void *Lookup(int key, int *index);
};

struct Branch {
    int GetCustomerGroupRating(int group, int flag);
};

extern "C" int Game_GetBestBuildingRatingBand(void)
{
    int best = 0;
    int i = 0;
    char *building = *(char **)(DAT_0057c670 + 0x200 +
                                *(int *)(DAT_0057c670 + 0x2ec) * 4);
    int count = *(int *)(building + 0x15c);

    if (count > 0) {
        do {
            Branch *branch = (Branch *)((IDMapHelper *)(building + 0x148))
                                 ->Lookup(i, 0);
            int j = 0;

            do {
                int value = branch->GetCustomerGroupRating(j, 1);
                if (value > best)
                    best = value;
                j++;
            } while (j < 8);
            i++;
        } while (i < count);
        if (best > 0x50)
            return 3;
        if (best > 0x3b)
            return 2;
        if (best > 0x28)
            return 1;
    }
    return 0;
}
