/* Stats_FreeRecordMap: frees every record of the statistics record map
   (0x510600). */
struct List_Node {
    void Reset(void);
};

struct IDMap {
    int *Lookup(int key, int *out);
};

extern void __cdecl Mem_Free(void *block);

void __fastcall Stats_FreeRecordMap(int object)
{
    if (*(int *)(object + 0x304) != 0) {
        int index = *(int *)(*(int *)(object + 0x304) + 0x14);

        while (--index >= 0) {
            void *record = ((struct IDMap *)*(void **)(object + 0x304))->Lookup(index, 0);

            if (record != 0)
                Mem_Free(record);
        }
        ((struct List_Node *)*(void **)(object + 0x304))->Reset();
    }
}
