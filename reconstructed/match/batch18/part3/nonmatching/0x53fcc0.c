extern "C" void *__cdecl Mem_Free(void *block);
extern "C" int __cdecl CRT_Fclose(void *stream);
extern "C" void __cdecl DeleteCriticalSection(void *section);

/* SoundPakManager_Destruct: releases the pak list and critical section
   (0x53fcc0). */
struct SoundPakManager {
    void Destroy();
};

void SoundPakManager::Destroy()
{
    int i;

    *(void **)this = (void *)0x55c864;
    i = *(int *)((char *)this + 0x238);
    while (0 < i) {
        i = i - 1;
        *(int *)((char *)this + 0x238) = i;
        if (*(int *)((char *)this + i * 0x1c + 8) != 0) {
            CRT_Fclose(*(void **)((char *)this + i * 0x1c + 0x8));
        }
        Mem_Free(*(void **)((char *)this + *(int *)((char *)this + 0x238) * 0x1c + 0xc));
        i = *(int *)((char *)this + 0x238);
    }
    {
        int node = *(int *)((char *)this + 0x628);

        while (node != 0) {
            int next = *(int *)(node + 0x50);
            Mem_Free((void *)node);
            *(int *)((char *)this + 0x628) = next;
            node = *(int *)((char *)this + 0x628);
        }
    }
    DeleteCriticalSection((void *)((char *)this + 0x23c));
    *(void **)this = (void *)0x55c840;
}
