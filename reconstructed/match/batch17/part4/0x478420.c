struct Game {
    void *GetPlayerBySlot(int slot);
    void *GetPlayerCity();
};

struct Player {
    void *FindRecordType2ByKey(int key);
};

struct GamePlan {
    int ComputeAverageEffect(int slot);
    int ComputeCategoryEffect(int slot, int category);
};

struct Branch {
    char pad0[0x30];
    int playerSlot;
    char pad1[0xc - 0x4];
    int recordKey;
    int GetPriceComparisonRating(int category, int *flag);
};

extern Game *DAT_0057c670;

int Branch::GetPriceComparisonRating(int category, int *flag)
{
    void *player = DAT_0057c670->GetPlayerBySlot(*(int *)((char *)this + 0x30));
    void *record = ((Player *)player)->FindRecordType2ByKey(
        *(int *)((char *)this + 0x3c));
    if (record == 0) {
        *flag = 0;
        return 0;
    }
    if (*(int *)((char *)record + 4) == 0) {
        *flag = 0;
        return 0;
    }
    *flag = 1;
    int rating;
    if (category == -1)
        rating = ((GamePlan *)record)->ComputeAverageEffect(
            *(int *)((char *)this + 0x30));
    else
        rating = ((GamePlan *)record)->ComputeCategoryEffect(
            *(int *)((char *)this + 0x30), category);
    void *city = ((Game *)player)->GetPlayerCity();
    rating = (((*(int *)((char *)city + 0x5c) + *(int *)((char *)city + 0x44)) *
                   -3 +
               100) *
              rating) /
             100;
    if (100 < rating)
        return 100;
    if (rating < 0)
        rating = 0;
    return rating;
}
