/* Sound_ApplySettings (0x5477a0). */
struct Sound {
    char pad00[0x1d0];
    int volume1d0;
    int volume1d4;
    int volume1d8;

    void LoadSpeechSet();
    int ConvertVolumeSetting(int value);
    void ApplySettings(int *settings);
};
extern "C" char DAT_00575090;
extern "C" int DAT_00575094;
extern "C" int DAT_00575098;
extern "C" int DAT_0057509c;

void Sound::ApplySettings(int *settings)
{
    *(int *)&DAT_00575090 = settings[0];
    DAT_00575094 = settings[1];
    DAT_00575098 = settings[2];
    DAT_0057509c = settings[3];
    *((char *)&DAT_00575090 + 1) = *((char *)settings + 1);
    LoadSpeechSet();
    volume1d0 = settings[1];
    volume1d4 = ConvertVolumeSetting(settings[2]);
    volume1d8 = ConvertVolumeSetting(settings[3]);
}
