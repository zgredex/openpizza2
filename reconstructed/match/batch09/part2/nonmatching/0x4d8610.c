/* AI_AddKnownRecord: appends a new known-record entry to the AI list
   (0x4d8610). */
struct List {
    void Add(void *item);
};

struct AI {
    void AddKnownRecord(int record);
};

extern void *__cdecl operator_new(unsigned int size);

void AI::AddKnownRecord(int record)
{
    int *entry = (int *)operator_new(8);

    if (entry != 0) {
        *entry = record;
        entry[1] = -1;
        ((struct List *)((char *)this + 0xfc8))->Add(entry);
    } else {
        int *empty = 0;
        ((struct List *)((char *)this + 0xfc8))->Add(empty);
    }
}
