/* Record_GetPairPositions (0x534830): copies the coordinate pair stored at
   +0x20 of the 0x48-byte record into the caller's Pair. */
struct Pair { int x; int y; };
struct Record48 {
    int id;
    int unused;
    int a;
    int b;
    double value;
    int x;
    int y;
    Pair pos;
    char pad[0x48 - 0x2c];
};

struct Record {
    char pad[0x48];
    int count;
    Record48 *items;
    void GetPairPositions(int index, int *first, Pair *second);
};

void Record::GetPairPositions(int index, int *first, Pair *second)
{
    Record48 *record;
    if (index < 0 || index >= count) return;
    record = &items[index];
    if (record->id == -1) return;
    first[0] = record->x;
    first[1] = record->y;
    *second = *(Pair *)((char *)items + index * 0x48 + 0x20);
}
