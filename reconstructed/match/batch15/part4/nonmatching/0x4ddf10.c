/* Non-matching candidate.
   First difference: offset 0x2e, 34 bytes differ.
   the loop matches, but the zero-return block is placed at the end instead of between the total check and the non-zero path.
   Kept for evidence; not part of the strict match set. */
extern void *DAT_0057c670;

struct Company {
    float SumValuesByCategory(unsigned category, int value);
};

struct Stats {
    int CountActiveCompanies();
    Company *GetActiveCompanyById(int index);
    float ComputeCompanySharePercent(int company, int value);
};

float Stats::ComputeCompanySharePercent(int company, int value)
{
    unsigned category =
        (unsigned)*(unsigned short *)(*(int *)((char *)DAT_0057c670 + 0x94) + 0xa);
    float total = 0.0f;
    int count = CountActiveCompanies();
    int index = 0;
    if (count > 0) {
        do {
            Company *entry = GetActiveCompanyById(index);
            float share = entry->SumValuesByCategory(category, value);
            total = share + total;
            index++;
        } while (index < count);
        if (total == 0.0f)
            return 0.0f;
        {
            float share =
                ((Company *)company)->SumValuesByCategory(category, value);
            return (share / total) * 100.0f;
        }
    }
    return 0.0f;
}
