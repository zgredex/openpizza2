/* City_GetListEndpoints: reads a list's first and last ids for a city
   (0x4897c0). Best genuine C++ attempt: 84 of 86 bytes. The compiler folds
   the two identical array reads into one load, so the `if` compares a
   register instead of the original memory operand. */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct City {
    char pad[0x74];
    char map[0x14];

    void GetListEndpoints(int city, int index, int *start, int *end);
};

void City::GetListEndpoints(int city, int index, int *start, int *end)
{
    int count = 0;
    short *p;
    short *record = (short *)((struct IDMap *)map)->Lookup(city, 0);

    if (record[(index * 3 + 0x1e) * 2] != -1) {
        p = &record[(index * 3 + 0x1e) * 2];
        do {
            p++;
            count++;
        } while (*p != -1);
    }
    *start = record[(index * 3 + 0x1e) * 2];
    *end = record[0x3b + count + index * 6];
}
