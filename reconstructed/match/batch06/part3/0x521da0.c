/* RefCounted_Free: releases a reference-counted object, letting the payload
   destroy itself when the count reaches one, then frees the wrapper
   (0x521da0).  Build: /O2 /TP. */
struct RefTarget {
    virtual void Destroy(int mode);
};

struct RefCounted {
    int count;
    RefTarget *target;
};

void __cdecl Mem_Free(void *block);

void __stdcall RefCounted_Free(RefCounted *object)
{
    if (object == 0)
        return;
    if (object->count == 1 && object->target != 0)
        object->target->Destroy(1);
    Mem_Free(object);
}
