/* NamedLockable_Construct: constructs a named critical-section wrapper
   (0x401280). */
struct CriticalSection {
    char pad[0x18];
};

extern "C" __declspec(dllimport) void __stdcall
InitializeCriticalSection(CriticalSection *section);

extern "C" char *__cdecl strcpy(char *destination, const char *source);

struct NamedLockable {
    char pad0[4];
    CriticalSection section;
    char name[0x38];
    int field50;
    int field54;

    NamedLockable *Construct(char *name);
};

NamedLockable *NamedLockable::Construct(char *name)
{
    *(void ***)this = (void **)0x55c2e8;
    InitializeCriticalSection(&section);
    if (name == 0)
        name = (char *)0x5630ec;
    strcpy((char *)this + 0x1c, name);
    *(int *)((char *)this + 0x54) = 0;
    *(int *)((char *)this + 0x50) = 0;
    return this;
}
