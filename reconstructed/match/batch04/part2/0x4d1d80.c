/* MapObject_Delete: destroying delete for a map object (0x4d1d80). */
extern void __cdecl Mem_Free(void *memory);

struct MapObject {
    void Destroy();
    void *Delete(unsigned char flags);
};

void *MapObject::Delete(unsigned char flags)
{
    Destroy();
    if (flags & 1)
        Mem_Free(this);
    return this;
}
