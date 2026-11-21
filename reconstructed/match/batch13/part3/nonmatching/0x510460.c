/* Stats_GetMaxTimelineCategoryValue (0x510460). */
struct UI {
    int GetMaxChildField10();
};
struct Stats {
    char pad00[0x304];
    int field304;
    int GetMinMapField10();
    float SumMaskedMapFloats(int row, int category, int mask);
    float GetMaxTimelineCategoryValue(int category);
};
extern "C" float DAT_0055c2e4;

float Stats::GetMaxTimelineCategoryValue(int category)
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
        float value = SumMaskedMapFloats(first, category, -1);
        if (value > maximum) {
            maximum = value;
        }
    }
    return maximum;
}
