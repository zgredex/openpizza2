/* UI_FindFreeBriefing: looks for a briefing slot with no assigned channel
   and claims it (0x54b160). */
struct IDMap {
    int *Lookup(int key, int *unused);
};

struct BriefingMgr {
    void GetChannelObject(int index, int flag);
    int FindFreeBriefing();
};

int BriefingMgr::FindFreeBriefing()
{
    char *self = (char *)this;
    int count = *(int *)(self + 0x18);
    int i;

    for (i = 0; i < count; i++) {
        int *briefing = ((IDMap *)(self + 4))->Lookup(i, 0);

        if (*(int *)((char *)briefing + 0x14) == 0) {
            GetChannelObject(i, 0);
            return 1;
        }
    }
    return 0;
}
