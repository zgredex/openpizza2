/* SoundBuffer_SetVolume (0x5411c0): scales the buffer's base volume and
   applies it to the DirectSound voice. */
struct IVoiceVtbl {
    char pad[0x44];
    int (__stdcall *SetVolume)(void *self, int value);
};

struct IVoice {
    IVoiceVtbl *vtbl;
};

struct SoundBuffer {
    char pad[0x14];
    int volume;
    char pad2[0x1c - 0x18];
    unsigned int baseVolume;
    char pad3[0x48 - 0x20];
    IVoice *voice;

    int SetVolume(float scale);
};

int SoundBuffer::SetVolume(float scale)
{
    int volume;
    int result;

    volume = (int)((double)baseVolume * scale);
    result = voice->vtbl->SetVolume(voice, volume);
    if (result >= 0) {
        this->volume = volume;
        return 0;
    }
    return 0x80070057;
}
