/* SpriteBase_Delete - 0x53a1f0, 30 bytes */
extern "C" void __cdecl Mem_Free(void *memory);

struct SpriteBase
{
    void Destructor();
    void *Delete(unsigned char flags);
};

void *SpriteBase::Delete(unsigned char flags)
{
    Destructor();
    if (flags & 1)
        Mem_Free(this);
    return this;
}
