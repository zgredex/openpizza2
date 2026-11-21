/* Stats_SumSixSlotValues: sums six consecutive slot values and optionally
   returns one of them (0x4dc660). */
struct Stats {
    int SumSixSlotValues(int slot, int index);
};

int Stats::SumSixSlotValues(int slot, int index)
{
    int sum = 0;
    int selected = 0;
    int n = 0;
    int *value = (int *)((char *)this + 0xce0 + slot * 0x18);

    do {
        sum += *value;
        if (n == index)
            selected = *value;
        n++;
        value++;
    } while (n < 6);
    if (index != -1)
        sum = selected;
    return sum;
}
