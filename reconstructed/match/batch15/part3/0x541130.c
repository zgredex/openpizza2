extern "C" double __cdecl log10(double);
struct IVoiceVtbl { char pad[0x40]; int (__stdcall *SetVolume)(void *self, int value); };
struct IVoice { IVoiceVtbl *vtbl; };
struct Sound { char pad[0x48]; IVoice *voice; int SetVolumeLogarithmic(int level); };
int Sound::SetVolumeLogarithmic(int level)
{
    unsigned value = 0;
    if (level != 0) {
        if (level < 0) {
            if (-10000 < level)
                value = (unsigned)(int)(log10(10000.0 / (level + 10000)) * -2000.0);
            else
                value = 0xffffd8f0;
        } else {
            if (level < 10000)
                value = (unsigned)(int)(log10(10000.0 / (10000 - level)) * 2000.0);
            else
                value = 10000;
        }
    }
    int result = voice->vtbl->SetVolume(voice, value);
    return ((result >= 0) - 1) & 0x80070057;
}
