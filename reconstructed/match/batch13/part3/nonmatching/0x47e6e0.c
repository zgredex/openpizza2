/* Map_CollectType351ToList (0x47e6e0). */
extern "C" void *operator_new(unsigned size);
extern "C" void *memset(void *dest, int value, unsigned count);

struct Grid {
    int CollectType351(void *list);
};
struct List {
    void Add(void *node);
};
struct Map {
    char pad00[0x14e0];
    struct Grid *grid14e0;
    char pad14e4[0x4b4];
    struct List list1998;

    void CollectType351ToList();
};

void Map::CollectType351ToList()
{
    int local[160];
    int count = grid14e0->CollectType351(local);

    if (count > 0) {
        int *cursor = local + 1;
        do {
            int *node = (int *)operator_new(0x20);
            memset(node, 0, 0x20);
            node[5] = cursor[-1];
            node[6] = *cursor;
            node[7] = 0;
            list1998.Add(node);
            cursor = cursor + 2;
            count = count - 1;
        } while (count != 0);
    }
}
