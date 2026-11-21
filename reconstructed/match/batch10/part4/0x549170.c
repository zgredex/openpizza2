/* Sound_StopMusic (0x549170): stops the buffer that is playing music and
   clears the sound's playback state under its lock. */
struct CS {
    void Enter();
    void Leave();
};

struct ISoundVtbl {
    char pad[0x54];
    void (__stdcall *StopBuffer)(void *self, void *buffer);
};

struct ISound {
    ISoundVtbl *vtbl;
};

struct Sound {
    char pad[8];
    ISound *device;
    char pad2[0x10 - 0xc];
    void *buffer;
    int bufferType;
    char pad3[0xfc - 0x18];
    char enabled;
    char pad4[0x178 - 0xfd];
    CS lock;

    void StopMusic();
};

void Sound::StopMusic()
{
    if (enabled == 0)
        return;
    lock.Enter();
    if (buffer != 0 && bufferType == 3) {
        device = *(ISound **)((char *)this + 8);
        device->vtbl->StopBuffer(device, buffer);
        buffer = 0;
        bufferType = 0;
    }
    lock.Leave();
}
