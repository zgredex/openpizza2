// City_GetTopProductCategory @ 0x4e2b70 (153 bytes)
// Sums the per-category weights of all city records and returns the best.

extern int DAT_0057dfc0[7];
extern char DAT_004e2c10[];

namespace CRT {
    void QSort(void *base, unsigned count, unsigned size,
               int (__cdecl *compare)(const void *, const void *));
}

class IDMap {
public:
    char pad[0x14];
    void *Lookup(int index, int *out);
};

class City {
public:
    char pad0[0x110];
    IDMap map;
    int count;

    int GetTopProductCategory();
};

int City::GetTopProductCategory()
{
    int categories[7];
    int i;

    for (i = 0; i < 7; i++)
        DAT_0057dfc0[i] = 0;
    DAT_0057dfc0[0] = -1;
    for (i = 0; i < 7; i++)
        categories[i] = i;
    for (i = 0; i < this->count; i++) {
        int *record = (int *)this->map.Lookup(i, 0);
        for (int j = 0; j < 6; j++)
            DAT_0057dfc0[j + 1] += *(int *)((char *)record + 0x1c0 + j * 4);
    }
    CRT::QSort(categories, 7, 4,
               (int (__cdecl *)(const void *, const void *))(void *)DAT_004e2c10);
    return categories[0];
}
