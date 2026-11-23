/* SoundBuffer_Init: constructs a sound buffer from a descriptor (0x540960). */
struct SoundBuffer {
    void Init(void *a, char *b, int c);
};

void SoundBuffer::Init(void *a, char *b, int c)
{
    *(int *)((char *)this + 4) = 1;
    *(void **)this = (void *)0x55c840;
    *(int *)((char *)this + 8) = 0;
    *(int *)((char *)this + 0xc) = 0;
    *(int *)((char *)this + 0x10) = *(int *)(b + 0x10);
    *(int *)((char *)this + 0x14) = *(int *)(b + 0x14);
    *(int *)((char *)this + 0x18) = *(int *)(b + 0x18);
    *(int *)((char *)this + 0x1c) = *(int *)(b + 0x1c);
    *(int *)((char *)this + 0x20) = *(int *)(b + 0x20);
    *(int *)((char *)this + 0x24) = *(int *)(b + 0x24);
    *(unsigned short *)((char *)this + 0x28) = *(unsigned short *)(b + 0x28);
    *(int *)((char *)this + 0x2c) = 0;
    *(int *)((char *)this + 0x30) = 0;
    *(char *)((char *)this + 0x34) = *(char *)(b + 0x34);
    *(int *)((char *)this + 0x38) = 0;
    *(int *)((char *)this + 0x3c) = 0;
    *(int *)((char *)this + 0x40) = 0;
    *(int *)((char *)this + 0x44) = 0;
    *(void **)this = (void *)0x55c874;
    (*(void (__stdcall **)(void *))*(void ***)a)(a);
    {
        void **vt = *(void ***)a;
        int result = (*(int (__stdcall **)(void *, int, char *))(vt[5]))(a,
            *(int *)(b + 0x48), (char *)this + 0x48);

        if (result >= 0 && a != 0) {
            *(int *)a = 0;
        }
    }
}
