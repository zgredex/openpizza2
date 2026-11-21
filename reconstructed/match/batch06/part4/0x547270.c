/* Sound_SetVolume: sets the device volume and returns the device's reported
   level, or zero when no volume was requested (0x547270).  Build: /O2 /TP. */
struct SoundDevice {
    int *vtable;
};

typedef void (__stdcall *SoundSetVolumeFn)(SoundDevice *device, unsigned volume,
                                           unsigned char *result);

struct Sound {
    char pad[8];
    SoundDevice *device;
    unsigned char SetVolume(unsigned volume);
};

unsigned char Sound::SetVolume(unsigned volume)
{
    unsigned char result = 0;

    if (volume != 0)
        ((SoundSetVolumeFn *)device->vtable)[0x3e](device, volume, &result);
    return result;
}
