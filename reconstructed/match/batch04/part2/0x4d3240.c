/* Car_Delete: destroying delete for a car object (0x4d3240). */
extern void __cdecl Mem_Free(void *memory);

struct Car {
    void Destroy();
    void *Delete(unsigned char flags);
};

void *Car::Delete(unsigned char flags)
{
    Destroy();
    if (flags & 1)
        Mem_Free(this);
    return this;
}
