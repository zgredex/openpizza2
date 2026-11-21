struct CriticalSection {
    void Enter();
    void Leave();
};

struct IVoiceVtbl {
    char pad0[0x54];
    void (__stdcall *fn54)(void *self, int value);
    char pad1[0x68 - 0x58];
    void (__stdcall *fn68)(void *self, int value);
};

struct IVoice {
    IVoiceVtbl *vtbl;
};

void __fastcall SoundBuffer_Release(void *buffer);

struct Sound {
    void StopPlaybackMode();
};

void Sound::StopPlaybackMode()
{
    int mode = *(int *)((char *)this + 0x104);
    *(int *)((char *)this + 0x104) = 0;
    if (*(char *)((char *)this + 0xfc) == 0)
        return;
    ((CriticalSection *)((char *)this + 0x178))->Enter();
    switch (mode) {
    case 1:
        {
            IVoice *voice = *(IVoice **)((char *)this + 8);
            voice->vtbl->fn68(voice, *(int *)((char *)this + 0x80));
        }
        break;
    case 2:
        break;
    case 3:
        if (*(char *)((char *)this + 0xff) != 0) {
            IVoice *voice = *(IVoice **)((char *)this + 8);
            voice->vtbl->fn54(voice, *(int *)((char *)this + 0x20));
            *(char *)((char *)this + 0xff) = 0;
        }
        *(int *)((char *)this + 0x20) = 0;
        break;
    default:
        ((CriticalSection *)((char *)this + 0x178))->Leave();
        return;
    }
    if (*(int *)((char *)this + 0x1d4) == 0)
        SoundBuffer_Release(this);
    ((CriticalSection *)((char *)this + 0x178))->Leave();
}
