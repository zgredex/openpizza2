/* UI_GetScrollRatio: converts a scroll position into a 0..1000 ratio
   (0x527dc0). */
struct UI {
    char pad[0x83b0];
    __int64 range;

    double GetScrollRatio(__int64 start, __int64 end);
};

double UI::GetScrollRatio(__int64 start, __int64 end)
{
    if (range == 0) {
        return 0.0;
    }
    return (double)(end - start) * 1000.0 / (double)range;
}
