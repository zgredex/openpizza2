/* Sound_StopBuffer: releases the active sound buffer and clears the slot
   (0x532b60). */
struct Buffer {
    virtual void Release(int flag);
};

struct Sound {
    char pad[0x138];
    Buffer *buffer;
    char pad2[0x184];
    int active;
    void StopBuffer();
};

void Sound::StopBuffer()
{
    if (active != 0) {
        Buffer *buffer = this->buffer;

        active = 0;
        if (buffer != 0)
            buffer->Release(1);
        this->buffer = 0;
    }
}
