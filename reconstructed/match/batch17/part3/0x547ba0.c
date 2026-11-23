struct IVoiceVtbl {
    char pad0[0x7c];
    void (__stdcall *setPrimary)(void *self, int buffer, int volume);
    void (__stdcall *setSecondary)(void *self, int buffer, int volume);
};

struct IVoice {
    IVoiceVtbl *vtbl;
};

struct Sound {
    char pad0[8];
    IVoice *voice;
    int secondaryBuffer;
    char pad1[0x10];
    int primaryBuffer;
    char pad2[0x5c];
    int primaryHandle;
    char pad3[0x78];
    char enabled;
    char pad4[7];
    int playbackMode;
    char pad5[0xc8];
    int primaryVolume;
    int secondaryVolume;
    int extraVolume;
    char SetVolumeSetting(int mode, int volume);
    void ApplyVolumesForPlaybackMode(int volume);
};

void Sound::ApplyVolumesForPlaybackMode(int volume)
{
    if (!SetVolumeSetting(playbackMode, volume))
        return;
    if (enabled == 0)
        return;
    switch (playbackMode) {
    case 1:
        voice->vtbl->setPrimary(voice, primaryHandle, primaryVolume);
        if (secondaryBuffer != 0)
            voice->vtbl->setSecondary(voice, secondaryBuffer, secondaryVolume);
        if (primaryBuffer != 0)
            voice->vtbl->setSecondary(voice, primaryBuffer, extraVolume);
        break;
    case 2:
        if (secondaryBuffer == 0)
            return;
        voice->vtbl->setSecondary(voice, secondaryBuffer, secondaryVolume);
        return;
    case 3:
        if (primaryBuffer != 0)
            voice->vtbl->setSecondary(voice, primaryBuffer, extraVolume);
        break;
    default:
        return;
    }
}
