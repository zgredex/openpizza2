/* Non-matching candidate.
   First difference: offset 0x0, 98 bytes differ.
   The original keeps this in ebp and total on the stack; the candidate
   keeps this in edx and total in edi, and the slot arrays use a 4-byte
   stride in the original. Kept for evidence. */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    char pad0[0x3c];
    IDMap objects;
    char pad1[0x50 - 0x40];
    int object_count;
    int CountProductUsageByCategory(int category, int *out);
};

int Game::CountProductUsageByCategory(int category, int *out)
{
    for (int clear = 0; clear < 0x40; clear++)
        out[clear] = 0;
    int total = 0;
    int index = 0;
    int count = *(int *)((char *)this + 0x50);
    if (count > 0) {
        do {
            int *object = (int *)objects.Lookup(index, 0);
            if (object[0xc] < 8) {
                int *source = object + 0x35;
                int *target = out + object[0xc];
                int remaining = 8;
                do {
                    if (*source == category) {
                        (*target)++;
                        total++;
                    }
                    source++;
                    target += 8;
                    remaining--;
                } while (remaining != 0);
            }
            index++;
        } while (index < count);
    }
    return total;
}
