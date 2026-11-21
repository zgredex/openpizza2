/* Object_Compare (0x4ed500). */
struct Entry {
    char pad0[0xc];
    int field0c;            /* 0x0c */
    int field10;            /* 0x10 */
};
struct Object {
    char pad0[0xc];
    int mode;               /* 0x0c */

    int Compare(Entry *a, Entry *b);
};
extern int abs(int value);

int Object::Compare(Entry *a, Entry *b)
{
    int d1;
    int d2;

    if (mode == 0x10) {
        if (a->field0c == b->field0c || a->field10 == b->field10)
            return 0xe;
        return 10;
    }
    d1 = a->field10 - b->field10;
    d2 = a->field0c - b->field0c;
    return abs(d2) * 3 + abs(d1) * 4;
}
