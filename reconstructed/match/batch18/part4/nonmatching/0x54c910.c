extern "C" int __stdcall CloseHandle(void *handle);
extern "C" void *__cdecl Mem_Free(void *block);

/* Sound_DestroyAllChannels: releases the channel and buffer maps and closes the
   worker handles (0x54c910). */
struct IDMap {
    void *Lookup(int index, int *unused);
};

struct SoundManager {
    void ShutdownThread();
    void DestroyAllChannels();
};

void SoundManager::DestroyAllChannels()
{
    ShutdownThread();
    {
        void *map = *(void **)((char *)this + 0xc4);
        int i;

        if (map != 0) {
            i = 0;
            if (0 < *(int *)((char *)map + 0x14)) {
                do {
                    Mem_Free(((IDMap *)map)->Lookup(i, 0));
                    map = *(void **)((char *)this + 0xc4);
                    i = i + 1;
                } while (i < *(int *)((char *)map + 0x14));
            }
            if (*(void **)((char *)this + 0xc4) != 0) {
                (*(void (__stdcall **)(int))**(void ***)((char *)this + 0xc4))(1);
            }
            *(void **)((char *)this + 0xc4) = 0;
        }
    }
    {
        void *map = *(void **)((char *)this + 200);
        int i;

        if (map != 0) {
            i = 0;
            if (0 < *(int *)((char *)map + 0x14)) {
                do {
                    Mem_Free(((IDMap *)map)->Lookup(i, 0));
                    map = *(void **)((char *)this + 200);
                    i = i + 1;
                } while (i < *(int *)((char *)map + 0x14));
            }
            if (*(void **)((char *)this + 200) != 0) {
                (*(void (__stdcall **)(int))**(void ***)((char *)this + 200))(1);
            }
            *(void **)((char *)this + 200) = 0;
        }
    }
    if (*(void **)((char *)this + 0x98) != 0) {
        CloseHandle(*(void **)((char *)this + 0x98));
        *(void **)((char *)this + 0x98) = 0;
    }
    if (*(void **)((char *)this + 0x9c) != 0) {
        CloseHandle(*(void **)((char *)this + 0x9c));
        *(void **)((char *)this + 0x9c) = 0;
    }
    if (*(void **)((char *)this + 0x94) != 0) {
        CloseHandle(*(void **)((char *)this + 0x94));
        *(void **)((char *)this + 0x94) = 0;
    }
}
