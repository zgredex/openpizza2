/* SoundBuffer_SetFreqAndPan: applies frequency and pan to a DirectSound voice
   (0x541290). */
struct IVoiceVtbl {
    char pad[0x40];
    int (__stdcall *SetPan)(void *self, int value, int flags);
    int (__stdcall *SetFrequency)(void *self, int value, int flags);
};

struct IVoice {
    IVoiceVtbl *vtbl;
};

struct SoundBuffer {
    char pad[0x5c];
    IVoice *voice;

    int SetFreqAndPan(int frequency, int pan);
};

int SoundBuffer::SetFreqAndPan(int frequency, int pan)
{
    int result;

    result = voice->vtbl->SetFrequency(voice, frequency, 0);
    if (result < 0)
        return 0x80070057;
    result = voice->vtbl->SetPan(voice, pan, 0);
    return ((result >= 0) - 1) & 0x80070057;
}
