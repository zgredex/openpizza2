/* Sound_TriggerSoundById: plays one sound slot at full volume (0x548040). */
struct Sound {
    char pad0[0x24];
    int sounds[1];
    char pad1[0xfc - 0x28];
    char enabled;
    void SetPosition(int sound, int zero, float volume);
    void TriggerSoundById(int index);
};

void Sound::TriggerSoundById(int index)
{
    if (enabled != 0 && index >= 0) {
        SetPosition(*(int *)((char *)this + index * 4 + 0x24), 0, 1.0f);
    }
}
