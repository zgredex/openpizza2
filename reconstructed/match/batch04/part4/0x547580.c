/* PC2 byte-match candidate: Sound_ReloadSpeechSetIfNeeded (0x547580,
   27 bytes).  Build: /O2 /TP.  Reloads the speech set when flagged. */
struct Sound {
    unsigned char pad_000[0xfe];
    unsigned char reload_flag;
    void LoadSpeechSet();
    void ReloadSpeechSetIfNeeded();
};

void Sound::ReloadSpeechSetIfNeeded()
{
    if (reload_flag) {
        LoadSpeechSet();
        reload_flag = 0;
    }
}
