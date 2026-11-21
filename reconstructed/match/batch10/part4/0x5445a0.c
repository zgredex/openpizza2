/* SoundBuffer_StopPlayback (0x5445a0): stops the DirectSound voice and
   releases its buffer. */
struct IVoiceVtbl {
    char pad[0x34];
    int (__stdcall *SetBuffer)(void *self, void *buffer);
    char pad2[0x48 - 0x38];
    int (__stdcall *Stop)(void *self);
};

struct IVoice {
    IVoiceVtbl *vtbl;
};

struct List {
    void DestroyObjects();
};

struct SoundBuffer {
    char pad[0x34];
    char hasObjects;
    char pad2[0x48 - 0x35];
    IVoice *voice;

    int StopPlayback();
};

int SoundBuffer::StopPlayback()
{
    int result;

    if (voice == 0)
        return 0x80070006;
    if (voice->vtbl->Stop(voice) < 0)
        return 0x80004005;
    if (hasObjects != 0)
        ((List *)this)->DestroyObjects();
    result = voice->vtbl->SetBuffer(voice, 0);
    return ((result >= 0) - 1) & 0x80004005;
}
