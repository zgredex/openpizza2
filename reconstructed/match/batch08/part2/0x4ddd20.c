/* Company_InvalidateAllBranchRatings: invalidates the rating cache of every
   branch record (0x4ddd20). */
struct IDMap {
    void *Lookup(int key, int *out);
};

void __fastcall Branch_InvalidateRatingCache(void *branch);

struct Company {
    char pad[0x148];
    int count;
    void InvalidateAllBranchRatings();
};

void Company::InvalidateAllBranchRatings()
{
    int index = 0;

    while (index < *(int *)((char *)this + 0x15c)) {
        void *record =
            ((struct IDMap *)((char *)this + 0x148))->Lookup(index, 0);

        Branch_InvalidateRatingCache(record);
        index++;
    }
}
