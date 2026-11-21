/* Stats_GetMaxCategoryValue (0x510390). */
struct UI {
    int GetMaxChildField10();
};
struct Stats {
    char pad00[0x304];
    int field304;
    int GetMinMapField10();
    float SumValuesByCategory(int row, int category);
    float GetMaxCategoryValue(int category);
};
extern "C" float DAT_0055c2e4;

float Stats::GetMaxCategoryValue(int category)
{
    float maximum = 0.0f;
    int first;
    int last;

    if (field304 == 0) {
        return DAT_0055c2e4;
    }
    first = GetMinMapField10();
    last = ((struct UI *)this)->GetMaxChildField10();
    for (; first <= last; first = first + 1) {
        float value = SumValuesByCategory(first, category);
        if (value > maximum) {
            maximum = value;
        }
    }
    return maximum;
}
