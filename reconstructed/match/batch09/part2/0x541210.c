/* SoundBuffer_Configure: resets the DirectSound buffer format (0x541210). */
struct SoundBufferVtbl;

struct SoundBuffer {
    struct SoundBufferVtbl *vtbl;
};

struct SoundBufferVtbl {
    char pad[0xc];
    void (__stdcall *setFormat)(void *self, int *format);
    char pad2[0x30 - 0x10];
    void (__stdcall *setFlags)(void *self, int a, int b, int flag);
};

int __stdcall SoundBuffer_Configure(struct SoundBuffer *buffer, char enable)
{
    int flag = 0;
    int format[5];

    if (enable)
        flag = 1;
    format[0] = 0x14;
    buffer->vtbl->setFormat(buffer, format);
    buffer->vtbl->setFlags(buffer, 0, 0, flag);
    return 0;
}
