// Resource_Read: bounded read from a resource stream.

extern "C" {
void *__cdecl memcpy(void *dst, const void *src, unsigned int size);
int CRT_Fseek(void *file, int offset, int origin);
unsigned int CRT_FreadLocked(void *dst, unsigned int size,
                             unsigned int count, void *file);
}

struct CS {
    void Enter();
    void Leave();
};

struct Stream {
    char pad0[8];
    unsigned int size;
    unsigned int base;
    unsigned int position;
    char pad1[4];
    void *file;
    int mode;
    unsigned int data;
};

struct Resource {
    unsigned int Read(void *dst, unsigned int size, Stream *stream);
};

unsigned int Resource::Read(void *dst, unsigned int size, Stream *stream)
{
    CS *cs = (CS *)((char *)this + 0x1688);
    unsigned int position;

    cs->Enter();
    position = stream->position;
    if (position + size >= stream->size)
        size = stream->size - position;
    if ((int)size < 0) {
        cs->Leave();
        return 0;
    }
    if (stream->mode != 2) {
        if (*(void **)((char *)this + 0x1ac0) != stream->file ||
            *(unsigned int *)((char *)this + 0x1abc) !=
                stream->base + position)
            CRT_Fseek(stream->file, stream->base + position, 0);
        size = CRT_FreadLocked(dst, 1, size, stream->file);
        *(unsigned int *)((char *)this + 0x1abc) =
            stream->base + stream->position + size;
        *(void **)((char *)this + 0x1ac0) = stream->file;
    } else {
        char *source = (char *)(stream->data + stream->base + position);
        memcpy(dst, source, size);
    }
    stream->position += size;
    cs->Leave();
    return size;
}
