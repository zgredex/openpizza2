/* Sound_SetListenerPosition: converts the double position to a 64-bit fixed
   point value and forwards it with the rolloff argument (0x54bf50). */
struct Sound {
    void UpdateListener(__int64 position, int rolloff);
    void SetListenerPosition(double position, int rolloff);
};

void Sound::SetListenerPosition(double position, int rolloff)
{
    UpdateListener((__int64)position, rolloff);
}
