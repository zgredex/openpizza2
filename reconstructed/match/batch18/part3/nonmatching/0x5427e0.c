extern "C" void *__cdecl Mem_Free(void *block);
extern "C" int __stdcall CloseHandle(void *handle);
extern "C" int __stdcall SetEvent(void *handle);
extern "C" int __stdcall WaitForSingleObject(void *handle, unsigned int timeout);
extern "C" void __cdecl DeleteCriticalSection(void *section);

/* SoundMixerThread_Destroy: shuts down and frees the mixer thread
   (0x5427e0). */
struct SoundMixerThread {
    void Destroy();
};

void SoundMixerThread::Destroy()
{
    int *self = (int *)this;

    *(void **)self = (void *)0x55c8f0;
    *(char *)((char *)self + 0x34) = 1;
    if ((void *)self[0xb] != 0) {
        SetEvent((void *)self[0xb]);
        if ((void *)self[0xc] != (void *)0xffffffff) {
            WaitForSingleObject((void *)self[0xc], 0xffffffff);
        }
        CloseHandle((void *)self[0xb]);
    }
    {
        int *node = (int *)self[1];

        self[3] = (int)node;
        if (node != 0) {
            self[3] = node[1];
            while (1) {
                (*(void (__stdcall **)(int))*(void **)(*node))(*node);
                node = (int *)self[3];
                if (node == 0) {
                    break;
                }
                self[3] = node[1];
            }
        }
    }
    DeleteCriticalSection(self + 5);
    {
        void *node = (void *)self[1];

        while (node != 0) {
            void *next = *(void **)((char *)node + 4);
            Mem_Free(node);
            node = next;
        }
    }
    self[1] = 0;
    self[3] = 0;
    self[4] = 0;
}
