struct Record {
    int object;
    int index;
};

struct IDMap {
    int unused;
    Record *Lookup(int index, int *out);
};

struct UI {
    void QueueControlCommand(int command, int arg1, int arg2);
};

struct GameData {
    char pad0[0x25c];
    UI *control25c;
    char pad1[4];
    UI *control264;
};

struct Stats {
    char pad0[0x1500];
    IDMap map;
    char pad1[0x10];
    int count;
    char pad2[0x1a08 - 0x1518];
    char flags[0x18];
    void ResetAverages();
    void BuildRanking();
};

extern GameData *DAT_0057c670;

void Stats::ResetAverages()
{
    int i;

    for (i = 0; i < 6; i++)
        ((int *)((char *)this + 0x1a08))[i] = 0;
    int total = *(int *)((char *)this + 0x1514);
    for (i = 0; i < total; i++) {
        Record *record = ((IDMap *)((char *)this + 0x1500))->Lookup(i, 0);
        if (*(char *)(record->object + 0x824) == 0) {
            int offset = record->index * 3;
            for (int j = 0; j < 9; j++) {
                *(char *)((char *)this + 0x1a08 + offset) = 1;
                offset++;
                if (offset > 0x17)
                    offset = 0;
            }
        }
    }
    if (DAT_0057c670->control264 != 0)
        DAT_0057c670->control264->QueueControlCommand(-0x18693, 0x23, 0);
    if (DAT_0057c670->control25c != 0)
        DAT_0057c670->control25c->QueueControlCommand(-0x18693, 0x23, 0);
    BuildRanking();
}
