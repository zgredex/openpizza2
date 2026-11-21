/* Record_SetRect48 (0x534320): stores a coordinate pair and a double into
   the 0x48-byte record at the given index. */
struct Pair { int a; int b; };
struct Record48 {
    int id;
    int unused;
    Pair pair;
    double value;
    char pad[0x48 - 0x18];
};

struct Record {
    char pad[0x48];
    int count;
    Record48 *items;
    int SetRect48(int index, int a, int b, double value);
};

int Record::SetRect48(int index, int a, int b, double value)
{
    Record48 *record;
    Pair tmp;
    if (index < 0 || index >= count) return 0;
    if (items[index].id == -1) return 0;
    record = &items[index];
    tmp.a = a;
    tmp.b = b;
    record->pair = tmp;
    items[index].value = value;
    return 1;
}
