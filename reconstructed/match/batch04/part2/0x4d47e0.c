/* City_Delete: destroying delete for a city object (0x4d47e0). */
extern void __cdecl Mem_Free(void *memory);

struct City {
    void Destroy();
    void *Delete(unsigned char flags);
};

void *City::Delete(unsigned char flags)
{
    Destroy();
    if (flags & 1)
        Mem_Free(this);
    return this;
}
