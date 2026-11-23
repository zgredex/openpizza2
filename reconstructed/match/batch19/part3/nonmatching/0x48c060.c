/* Market_ComputeWeightedAveragePrice (0x48c060). */

struct Game {
    int CountActiveCompanies();
    int GetActiveCompanyById(int id);
};

struct Market {
    char pad0[0xa8];
    int prices[1];              /* 0xa8 */

    double ComputeWeightedAveragePrice(int *state, void *object);
};

double Market::ComputeWeightedAveragePrice(int *state, void *object)
{
    int total = 0;
    float sum = 0.0f;
    int i = 0;

    if (state[7] == 0) {
        *state = 0;
        return 0.0;
    }
    if (*state == 0) {
        state[7] = 0;
        return 0.0;
    }
    int count = ((Game *)object)->CountActiveCompanies();

    if (count > 0) {
        do {
            int company = ((Game *)object)->GetActiveCompanyById(i);

            if (company != 0) {
                int *values = (int *)(company + 0x64);
                int *prices = (int *)((char *)this + 0xa8);
                int k = 0x56;

                do {
                    int value = *values++;
                    int price = *prices++;

                    total = total + value;
                    k--;
                    sum = (float)(*(double *)(price + 0xc0) *
                                      (double)value * 0.001 +
                                  sum);
                } while (k != 0);
            }
            i++;
        } while (i < count);
        if (total != 0)
            goto done;
    }
    sum = 100.0f;
    total = 200000;
done:
    state[7] = 0;
    int old = *state;
    *state = 0;
    return (sum / total) * (float)state[4] * (float)old;
}
