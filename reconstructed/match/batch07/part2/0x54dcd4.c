/* Stream_AttachBuffer (0x54dcd4, 48 bytes).  Build: /O1 /TP (the original
   uses memory-form compares and pop-ecx cleanup, i.e. size optimization). */
extern "C" void Mem_Free(void *memory);

struct Stream {
    void AttachBuffer(int buffer, int size, int capacity);
};

void Stream::AttachBuffer(int buffer, int size, int capacity)
{
    if (*(int *)((char *)this + 4) != 0 &&
        *(void **)((char *)this + 0x10) != 0)
        Mem_Free(*(void **)((char *)this + 0x10));
    *(int *)((char *)this + 0x10) = buffer;
    *(int *)((char *)this + 4) = capacity;
    *(int *)((char *)this + 0x14) = size;
}
