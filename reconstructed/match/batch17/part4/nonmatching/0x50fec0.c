struct IDMap {
    int unused;
    int *Lookup(int index, int *out);
};

struct GameData {
    char pad[0xa8];
    int values[1];
};

struct PlayerStats {
    char pad0[0x48];
    IDMap map;
    char pad1[0x5c - 0x4c];
    int count;
    char pad2[0x64 - 0x60];
    int byType[0x56];
    int byCategory[7];
    int total;
    void Reset();
};

extern GameData *DAT_0057c670;

void PlayerStats::Reset()
{
    int i;
    for (i = 0; i < 7; i++)
        ((int *)((char *)this + 0x1bc))[i] = 0;
    for (i = 0; i < 0x56; i++)
        ((int *)((char *)this + 0x64))[i] = 0;
    int j = 0;
    int total = 0;
    if (0 < *(int *)((char *)this + 0x5c)) {
        do {
            int *record = ((IDMap *)((char *)this + 0x48))->Lookup(j, 0);
            if (*(unsigned char *)((char *)record + 0x11) == 0) {
                int valueBase = *(int *)((char *)DAT_0057c670 + 0xa8 +
                                         *(unsigned char *)((char *)record + 4) * 4);
                int value = *(int *)(valueBase + 0xac +
                                     *(unsigned char *)((char *)record + 6) * 4);
                *(int *)((char *)this + 0x64 +
                         *(unsigned char *)((char *)record + 4) * 4) += value;
                *(int *)((char *)this + 0x1bc +
                         *(unsigned char *)((char *)record + 5) * 4) += value;
                total = total + value;
            }
            j++;
        } while (j < *(int *)((char *)this + 0x5c));
        if (0 < total) {
            int *value = (int *)((char *)this + 0x1bc);
            for (i = 7; i != 0; i--) {
                *value = *value * 100 / total;
                value++;
            }
        }
    }
    *(int *)((char *)this + 0x1d8) = total;
}
