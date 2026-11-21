/* Stream_AllocateAttachedBuffer: allocates a 0x200-byte block and attaches it
   as the stream buffer (0x54dca7).  Build: /O1 /TP. */
extern "C" void *__cdecl operator_new(unsigned size);

struct Stream {
    void AttachBuffer(void *base, void *end, int flag);
    int AllocateAttachedBuffer();
};

int Stream::AllocateAttachedBuffer()
{
    void *block = operator_new(0x200);

    if (block == 0)
        return -1;
    AttachBuffer(block, (char *)block + 0x200, 1);
    return 1;
}
