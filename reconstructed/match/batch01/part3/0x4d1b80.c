/* RecipeTopping_Delete - 0x4d1b80, 30 bytes */
extern "C" void __cdecl Mem_Free(void *memory);

struct RecipeTopping
{
    void Destroy();
    void *Delete(unsigned char flags);
};

void *RecipeTopping::Delete(unsigned char flags)
{
    Destroy();
    if (flags & 1)
        Mem_Free(this);
    return this;
}
