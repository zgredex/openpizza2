/* Company_Delete: destroying delete for a company object (0x4dd8d0). */
extern void __cdecl Mem_Free(void *memory);

struct Company {
    void Destroy();
    void *Delete(unsigned char flags);
};

void *Company::Delete(unsigned char flags)
{
    Destroy();
    if (flags & 1)
        Mem_Free(this);
    return this;
}
