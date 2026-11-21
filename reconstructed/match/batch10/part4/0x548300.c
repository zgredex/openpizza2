/* Sound_PlayTrackIfSelected (0x548300): plays the indexed music track when it
   is the track currently selected for the player. */
extern "C" {
extern int DAT_0057c670;
}

struct IDMap {
    int *Lookup(int index, int *value);
};

struct Game {
    char pad[4];
    IDMap map;
    char pad2[0x2f4 - 0x8];
    int selectedTrack;
    char pad3[0x2fc - 0x2f8];
    int currentTrack;
};

struct Sound {
    char pad[0x24];
    int tracks[0x36];

    void SetParam(int value, int flags);
    void PlayTrackIfSelected(int index);
};

void Sound::PlayTrackIfSelected(int index)
{
    Game *game;
    int selected;
    int *record;

    if (*(char *)((char *)this + 0xfc) == 0)
        return;
    game = (Game *)DAT_0057c670;
    selected = *(int *)((char *)game + 0x2fc);
    record = game->map.Lookup(*(int *)((char *)game + 0x2f4), 0);
    if (selected != *(int *)((char *)record + 0xfa8))
        return;
    SetParam(*(int *)((char *)this + index * 4 + 0x24), 0);
}
