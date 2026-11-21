/* Sound_InitSpeechVoice (0x5476f0). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
extern "C" char *DAT_0057c670;
extern "C" char *strcpy(char *dest, const char *source);

struct Sound {
    void LoadSpeechSet();
    void InitSpeechVoice();
};

void Sound::InitSpeechVoice()
{
    char *record = (char *)((struct IDMap *)(DAT_0057c670 + 4))
                       ->Lookup(*(int *)(DAT_0057c670 + 0x2f4), 0);

    strcpy((char *)this + 0x174, record + 0x44);
    LoadSpeechSet();
    *(int *)((char *)this + 0x144) = 0;
    *(int *)((char *)this + 0x14c) = 0;
    *(int *)((char *)this + 0x170) = 0x3f800000;
    *(int *)((char *)this + 0x18) = 1000;
}
