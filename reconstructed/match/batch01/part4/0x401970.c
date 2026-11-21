/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
struct NamedLockable {
    void Construct(const char *name);
};

struct ResourceManager {
    ResourceManager *Construct(void);
};

extern "C" char * __cdecl strcpy(char *dst, const char *src);

ResourceManager *ResourceManager::Construct(void)
{
    int i;
    char *base = (char *)this;

    ((NamedLockable *)(base + 0x1688))->Construct(0);
    *(void **)base = (void *)0x55c2f0;
    *(int *)(base + 0x1abc) = -1;
    *(int *)(base + 0x1ac0) = 0;
    *(int *)(base + 0x1684) = 0;
    *(int *)(base + 0x1ab8) = 1;
    *(char *)(base + 0x19b0) = 0;
    strcpy(base + 0x16a4, (const char *)0x56315c);
    for (i = 0; i < 20; i++)
        *(int *)(base + 0x16f4 + i * 0x24) = 0;
    *(int *)(base + 0x1ab4) = 0;
    return this;
}
