/* Sound_StartSpeech: starts a speech sound at its configured position
   (0x5483d0). */
typedef void (__stdcall *SoundMethod58)(void *object, int first, int second);

struct Sound {
    char pad[8];

    void UpdateVolumeByCitySize(int size);
    void SetPosition(int position, int flag, int value);

    void StartSpeech(int speech);
};

void Sound::StartSpeech(int speech)
{
    if (!*(char *)((char *)this + 0xfc)) {
        return;
    }
    UpdateVolumeByCitySize(speech);
    if (*(char *)((char *)this + 0x16a) != 0) {
        return;
    }
    SetPosition(*(int *)((char *)this + 0x88), 1, 0x3f800000);
    if (*(unsigned int *)((char *)this + 0x1d0) > 0) {
        void *object = *(void **)((char *)this + 8);
        void *vtbl = *(void **)object;

        (*(SoundMethod58 *)((char *)vtbl + 0x58))(
            object, *(int *)((char *)this + 0x8c), 1);
    }
    *(char *)((char *)this + 0x16a) = 1;
}
