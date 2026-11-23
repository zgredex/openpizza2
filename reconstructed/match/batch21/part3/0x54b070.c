// MessageList_FindFreeSlot @ 0x54b070 (156 bytes)
// Scans the nine briefing slots and returns the first free one, also
// reporting the current maximum end time.

extern "C" void *__cdecl memset(void *, int, unsigned int);

struct IDMapHelper {
    void *Lookup(int key, int *index);
};

class MessageList {
public:
    char pad00[0x18];
    int count;              // 0x18
    char pad1c[4];
    int maxValue;           // 0x20
    char pad24[4];
    int addend;             // 0x28
    int base;               // 0x2c

    int FindFreeSlot(int *out);
};

int MessageList::FindFreeSlot(int *out)
{
    int used[9];
    int i;
    int count;

    memset(used, 0, sizeof(used));
    *out = maxValue;
    i = 0;
    count = this->count;
    if (count > 0) {
        do {
            int *entry = (int *)((IDMapHelper *)((char *)this + 4))
                             ->Lookup(i, 0);
            if (entry[2] != -1) {
                int slot = entry[2] - base;
                if (slot >= 0 && slot < 9)
                    used[slot] = 1;
                if (entry[3] + addend > *out)
                    *out = entry[3] + addend;
            }
            i++;
        } while (i < count);
    }
    for (i = 0; i < 9; i++) {
        if (used[i] == 0)
            return base + i;
    }
    return -1;
}
