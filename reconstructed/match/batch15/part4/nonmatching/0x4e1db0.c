/* Non-matching candidate.
   First difference: offset 0x5a, 3 bytes differ.
   Only the register pair for the excluded-order comparison is swapped (ecx/edx).
   Kept for evidence; not part of the strict match set. */

extern void *DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct GameObject {
    int State_Is2DOr2E();
};

struct AI {
    char pad0[0x1b8];
    IDMap objects;
    char pad1[0x1cc - 0x1bc];
    int object_count;
    char pad2[0x1d8 - 0x1d0];
    int excluded;
    int CountActiveTargetsByState(int state);
};

int AI::CountActiveTargetsByState(int state)
{
    int total = 0;
    int count = object_count;
    int index = 0;
    if (count > 0) {
        do {
            int *entry = (int *)objects.Lookup(index, 0);
            char *object = (char *)((IDMap *)((char *)DAT_0057c670 + 0x3c))
                               ->Lookup(entry[0], 0);
            if ((state == -1 || *(int *)(object + 0x30) == state) &&
                *(char *)(object + 0x104) == 1 &&
                *(int *)(object + 0xfc) != excluded) {
                if (((GameObject *)object)->State_Is2DOr2E() == 0)
                    total++;
            }
            index++;
        } while (index < count);
    }
    return total;
}
