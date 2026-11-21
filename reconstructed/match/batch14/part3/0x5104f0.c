/* Stats_AverageActiveCategories (0x5104f0): averages the mapped input values
   of the active categories flagged in an eight-byte array. */
struct Stats {
    int MapInputIndex(int index);
    float AverageActiveCategories(unsigned char *flags);
};

float Stats::AverageActiveCategories(unsigned char *flags)
{
    int sum = 0;
    int count = 0;
    int indices[8];
    int i;

    for (i = 0; i < 8; i++) {
        if (flags[i] == 1)
            indices[count++] = i;
    }
    if (count == 0)
        return 0.0f;
    for (i = 0; i < count; i++)
        sum += MapInputIndex(indices[i]);
    return (float)sum / count;
}
