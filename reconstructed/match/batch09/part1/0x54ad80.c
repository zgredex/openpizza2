/* UI_DestroyBriefingList: frees every record of a briefing list and resets
   it (0x54ad80). */
struct IDMap {
    int *Lookup(int key, int *out);
};

struct List_Node {
    void Reset(void);
};

struct UI {
    void RemoveAllById(int id);
};

extern void __cdecl Mem_Free(void *block);

void __fastcall UI_DestroyBriefingList(void *object)
{
    int count;
    int index;

    ((struct UI *)object)->RemoveAllById(1);
    count = *(int *)((char *)object + 0x18);
    index = 0;
    if (count > 0) {
        do {
            void *record = ((struct IDMap *)((char *)object + 4))->Lookup(index, 0);

            Mem_Free(record);
            index++;
        } while (index < count);
    }
    ((struct List_Node *)((char *)object + 4))->Reset();
}
