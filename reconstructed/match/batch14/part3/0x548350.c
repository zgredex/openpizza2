/* Sound_UpdateVolumeByCitySize (0x548350): scales the current sound volume
   when the player's city changes. */
struct Game {
    int CountRecordsWithFieldA0();
};

struct SoundGlobal {
    char pad[0x9c];
    Game *currentPlayer;
};

extern SoundGlobal *DAT_0057c670;

typedef void (__stdcall *SetVolumeFn)(void *self, int channel, int volume);

struct Sound {
    char pad[8];
    void *device;
    char pad2[0x8c - 0xc];
    int channel;
    char pad3[0x1d0 - 0x90];
    int volumeScale;

    void UpdateVolumeByCitySize(Game *player);
};

void Sound::UpdateVolumeByCitySize(Game *player)
{
    if (volumeScale != 0 && DAT_0057c670->currentPlayer == player) {
        int count = player->CountRecordsWithFieldA0();
        unsigned int value = (count * 10000) / 40;

        if (value > 10000)
            value = 10000;
        (*(SetVolumeFn *)(*(char **)device + 0x7c))(device, channel,
            (value * volumeScale) / 10000);
    }
}
