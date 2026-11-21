/* Sound_StopSpeech: stops any active speech buffer and updates the city-size
   volume (0x548430). */
struct ISoundVtbl {
    char pad[0xa8];
    void (__stdcall *StopBuffer)(void *self, int buffer);
};

struct ISound {
    ISoundVtbl *vtbl;
};

struct Sound {
    void UpdateVolumeByCitySize(int size);
    void StopSpeech(int size);
};

void Sound::StopSpeech(int size)
{
    char *self = (char *)this;
    ISound *device;

    if (*(char *)(self + 0xfc) != 0 && *(char *)(self + 0x16a) != 0) {
        if (*(unsigned int *)(self + 0x1d0) > 0) {
            device = *(ISound **)(self + 8);
            device->vtbl->StopBuffer(device, *(int *)(self + 0xf4));
        }
        UpdateVolumeByCitySize(size);
    }
}
