/* UI_FreeObjectPairs: frees every object stored in a UI pair array
   (0x532aa0). */
struct Array {
    void *GetPtr(int index);
    void Clear();
};

extern "C" void Mem_Free(void *block);

extern "C" void __fastcall UI_FreeObjectPairs(int param_1)
{
    int count = *(int *)(param_1 + 0x2b8);
    int i;
    void *entry;

    for (i = 0; i < count; i++) {
        entry = ((Array *)(param_1 + 0x2a8))->GetPtr(i);
        if (entry != 0)
            Mem_Free(entry);
    }
    ((Array *)(param_1 + 0x2a8))->Clear();
}
