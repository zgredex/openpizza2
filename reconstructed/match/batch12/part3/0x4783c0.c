/* Branch_GetPriceRating (0x4783c0). */

struct Branch {
    int GetPriceRating(int index);
};

void __fastcall Branch_RecomputeMenuPriceRatings(Branch *self);

int Branch::GetPriceRating(int index)
{
    int sum = 0;
    int i;

    if (*(int *)((char *)this + 0x1714) == 0) {
        Branch_RecomputeMenuPriceRatings(this);
    }
    if (index == -1) {
        int *ratings = (int *)((char *)this + 0x179c);
        i = 8;
        do {
            sum += *ratings;
            ratings++;
        } while (--i != 0);
        sum = sum / 8;
    } else {
        sum = *(int *)((char *)this + index * 4 + 0x179c);
    }
    if (sum < 0) {
        return 0;
    }
    if (sum > 100) {
        sum = 100;
    }
    return sum;
}
