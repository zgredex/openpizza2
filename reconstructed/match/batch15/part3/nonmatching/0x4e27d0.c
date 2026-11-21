/* Non-matching candidate.
   First difference: offset 0x4d, 3 bytes differ.
   Only the register pair of the target/object comparison is swapped (ecx/edx).
   Kept for evidence; not part of the strict match set. */
extern void *DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    char pad0[0x1b8];
    IDMap objects;
    char pad1[0x1cc - 0x1bc];
    int object_count;
    int CountPlayerObjectsByType(void *target, int type, int category);
};

int Game::CountPlayerObjectsByType(void *target, int type, int category)
{
    int count = 0;
    int index = 0;
    if (*(int *)((char *)this + 0x1cc) > 0) {
        do {
            int *entry = (int *)objects.Lookup(index, 0);
            if (entry[1] == type) {
                int object = (int)((IDMap *)((char *)DAT_0057c670 + 0x3c))
                                 ->Lookup(entry[0], 0);
                if (*(int *)(object + 0x74) != 0 &&
                    *(int *)(object + 0xf4) == *(int *)((char *)target + 0x16f0) &&
                    (*(int *)(object + 0xa4) == category || category == -1))
                    count++;
            }
            index++;
        } while (index < *(int *)((char *)this + 0x1cc));
    }
    return count;
}
