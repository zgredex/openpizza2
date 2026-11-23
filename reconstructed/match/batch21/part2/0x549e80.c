// Sound_PlayBuildingSpecialSfx @ 0x549e80 (156 bytes)
// Builds the city-specific special building sound name and plays it.

extern "C" int String_Format(char *buffer, const char *format, ...);

extern char DAT_005762e0[];
extern char DAT_00576308[];
extern char DAT_0057630c[];
extern char DAT_00576310[];
extern char DAT_00576314[];
extern char DAT_00576318[];
extern char DAT_0057631c[];
extern char DAT_00576320[];
extern char DAT_00576324[];
extern char DAT_00576328[];
extern char DAT_0057632c[];

class Sound {
public:
    char pad0[0xfc];
    unsigned char enabled;

    void PlayChannel(const char *name, int loop, float volume, int flags);
    void PlayBuildingSpecialSfx(int id);
};

void Sound::PlayBuildingSpecialSfx(int id)
{
    char buffer[260];
    char *city;

    if (!enabled)
        return;
    switch (id) {
    case 0:
        city = DAT_0057632c;
        break;
    case 1:
        city = DAT_00576328;
        break;
    case 2:
        city = DAT_00576324;
        break;
    case 3:
        city = DAT_00576320;
        break;
    case 4:
        city = DAT_0057631c;
        break;
    case 5:
        city = DAT_00576318;
        break;
    case 6:
        city = DAT_00576314;
        break;
    case 7:
        city = DAT_00576310;
        break;
    case 8:
        city = DAT_0057630c;
        break;
    case 9:
        city = DAT_00576308;
        break;
    default:
        return;
    }
    String_Format(buffer, DAT_005762e0, city);
    PlayChannel(buffer, 1, 1.0f, 0);
}
