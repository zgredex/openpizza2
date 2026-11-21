/* Game_FreeSubmapObjects: frees every object of the submap list and destroys
   the list (0x4810e0). */
struct IDMapHelper {
    void *Lookup(int index, int *result);
};

struct ListObject {
    virtual void Destroy(int flag);
};

extern "C" void __cdecl Mem_Free(void *memory);

extern "C" void __fastcall Game_FreeSubmapObjects(char *this_)
{
    if (*(void **)(this_ + 0x1a28) != 0) {
        int count = *(int *)(*(int *)(this_ + 0x1a28) + 0x14);
        int index;

        for (index = 0; index < count; index++)
            Mem_Free(((IDMapHelper *)*(void **)(this_ + 0x1a28))
                         ->Lookup(index, 0));
        if (*(ListObject **)(this_ + 0x1a28) != 0)
            (*(ListObject **)(this_ + 0x1a28))->Destroy(1);
        *(void **)(this_ + 0x1a28) = 0;
    }
}
