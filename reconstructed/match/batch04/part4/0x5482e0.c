/* PC2 byte-match candidate: Sound_PlayEffectByIndex (0x5482e0, 29 bytes).
   Build: /O2 /TP.  Plays a cached effect entry when sound is enabled. */
struct Sound {
    unsigned char pad_000[0x24];
    int effects[0x36];
    unsigned char enabled;
    void SetParam(int value, int extra);
    void PlayEffectByIndex(int index);
};

void Sound::PlayEffectByIndex(int index)
{
    if (enabled)
        SetParam(effects[index], 0);
}
