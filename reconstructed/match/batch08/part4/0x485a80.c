/* Sound_SetVolumePreset: applies and caches a volume preset (0x485a80). */
extern void *DAT_0057ba0c;

struct Sound {
    void ApplyVolumePreset(int preset);
    void SetVolumePreset(int preset);
};

void Sound::SetVolumePreset(int preset)
{
    if (preset >= 0 && preset < 3) {
        *(int *)((char *)this + 0x2da0) = preset;
        ((Sound *)DAT_0057ba0c)->ApplyVolumePreset(preset);
    }
    if (*(int *)((char *)this + 0x33c) == 0)
        *(int *)((char *)this + 0x384) = *(int *)((char *)this + 0x2da0);
}
