/* Sound_CheckSpeechState (0x548480, 47 bytes).  Build: /O2 /TP.
   Recomputes the speech volume while speech is active and the game is in
   state 4. */
extern int DAT_0057c670;

struct Sound {
    void UpdateVolumeByCitySize(int value);
    void CheckSpeechState(int value);
};

void Sound::CheckSpeechState(int value)
{
    if (*(char *)((char *)this + 0xfc) != 0 &&
        *(char *)((char *)this + 0x16a) != 0 &&
        *(int *)(DAT_0057c670 + 0x290) == 4)
        UpdateVolumeByCitySize(value);
}
