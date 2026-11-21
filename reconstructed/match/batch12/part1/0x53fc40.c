/* SoundBuffer_ConstructBase: initialises the base sound buffer object
   (0x53fc40). */
extern char DAT_0055c840;
extern char DAT_0055c864;
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void *section);

struct SoundBuffer {
    SoundBuffer *ConstructBase();
};

SoundBuffer *SoundBuffer::ConstructBase()
{
    int *slot;
    int i;

    *(int *)((char *)this + 4) = 1;
    *(void **)this = &DAT_0055c840;
    *(int *)((char *)this + 0x238) = 0;
    InitializeCriticalSection((char *)this + 0x23c);
    *(int *)((char *)this + 0x628) = 0;
    *(void **)this = &DAT_0055c864;
    *(char *)((char *)this + 0x524) = 0;
    slot = (int *)((char *)this + 0x268);
    i = 0x14;
    do {
        *slot = 0;
        slot = (int *)((char *)slot + 0x24);
        i--;
    } while (i != 0);
    return this;
}
