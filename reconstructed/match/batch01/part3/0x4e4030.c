/* FurnitureType_Delete - 0x4e4030, 30 bytes */
extern "C" void __cdecl Mem_Free(void *memory);

struct FurnitureType
{
    void Destroy();
    void *Delete(unsigned char flags);
};

void *FurnitureType::Delete(unsigned char flags)
{
    Destroy();
    if (flags & 1)
        Mem_Free(this);
    return this;
}
