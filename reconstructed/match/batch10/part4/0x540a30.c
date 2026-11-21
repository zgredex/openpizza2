/* SoundBuffer_FillFromSample (0x540a30): locks the sound buffer and fills it
   from the given sample, then unlocks it. */
struct SoundSample {
    int ReadPCM(void *buffer, int size);
};

struct SoundBuffer {
    char pad[0x10];
    int size;

    void *LockSample(int offset, int size);
    int UnlockSample();
    int FillFromSample(SoundSample *sample);
};

int SoundBuffer::FillFromSample(SoundSample *sample)
{
    void *buffer;
    int result;

    buffer = LockSample(0, size);
    if (buffer == 0)
        return 0x80004005;
    result = sample->ReadPCM(buffer, size);
    if (result < 0) {
        UnlockSample();
        return result;
    }
    return UnlockSample();
}
