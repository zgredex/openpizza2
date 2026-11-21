/* ConstructionOrder_Delete - 0x4e5da0, 30 bytes */
extern "C" void __cdecl Mem_Free(void *memory);

struct ConstructionOrder
{
    void Destructor();
    void *Delete(unsigned char flags);
};

void *ConstructionOrder::Delete(unsigned char flags)
{
    Destructor();
    if (flags & 1)
        Mem_Free(this);
    return this;
}
