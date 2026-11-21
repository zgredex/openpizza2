/* Sound_PlayPoliceSfx: plays the police siren when the flag at 0xfc is set
   (0x548d90). */
void __stdcall Sound_PlayChannel(const char *name, int loop, float volume,
                                 int flags);
extern char STR_00576168[];

struct Sound {
    char pad[0xfc];
    unsigned char enabled;
    void PlayPoliceSfx();
};

void Sound::PlayPoliceSfx()
{
    if (enabled)
        Sound_PlayChannel(STR_00576168, 1, 1.0f, 0);
}
