/* Stats_GetMaxTimelineCount: returns the largest plan-step count over the
   visible timeline range (0x510400). */
struct Stats {
    char pad[0x304];
    int field304;

    int GetMinMapField10();
    int GetMaxChildField10();
    int CountPlanSteps(int first, int second, int third);

    int GetMaxTimelineCount(int param);
};

int Stats::GetMaxTimelineCount(int param)
{
    int maximum = 0;
    int first;
    int last;

    if (field304 == 0) {
        return 0;
    }
    first = GetMinMapField10();
    last = GetMaxChildField10();
    while (first <= last) {
        int count = CountPlanSteps(first, param, -1);

        if (count > maximum) {
            maximum = count;
        }
        first++;
    }
    return maximum;
}
