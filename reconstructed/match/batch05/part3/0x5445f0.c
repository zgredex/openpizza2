/* Sound_RewindBuffer: rewinds the sound buffer and normalizes the result (0x5445f0). */
struct ISoundBufferVtbl {
    char pad[0x34];
    int (__stdcall *Method)(void *self, unsigned int position);
};

struct ISoundBuffer {
    ISoundBufferVtbl *vtbl;
};

struct Sound {
    char pad[0x48];
    ISoundBuffer *buffer;
    unsigned int RewindBuffer(unsigned int position);
};

unsigned int Sound::RewindBuffer(unsigned int position)
{
    int result = buffer->vtbl->Method(buffer, position);

    return ((result >= 0) - 1) & 0x80004005;
}
