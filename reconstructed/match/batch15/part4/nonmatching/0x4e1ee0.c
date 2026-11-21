/* Non-matching candidate.
   First difference: offset 0x74, 2 bytes differ.
   loop-bound reload of this->object_count uses eax in the original and edx in the candidate.
   Kept for evidence; not part of the strict match set. */
extern void *DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct AI {
    char pad0[0x1b8];
    IDMap objects;
    char pad1[0x1cc - 0x1bc];
    int object_count;
    int CountAvailableTargets(int state);
};

int AI::CountAvailableTargets(int state)
{
    int total = 0;
    int index = 0;
    if (object_count > 0) {
        do {
            int *record = (int *)objects.Lookup(index, 0);
            char *object = (char *)((IDMap *)((char *)DAT_0057c670 + 0x3c))
                               ->Lookup(record[0], 0);
            if (record[1] == state && *(int *)(object + 0xa4) == -1 &&
                *(int *)(object + 0xfc) != 0 &&
                *(char *)(object + 0x104) != 0 &&
                *(int *)(object + 0x74) == 0)
                total++;
            index++;
        } while (index < object_count);
    }
    return total;
}
