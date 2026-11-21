/* Object_PlayStateSound: plays a sound effect matching the object state
   (0x50d440). */
extern int *DAT_0057c670;
extern struct Sound *DAT_0057ba0c;

struct Player {
    char pad[0x64];
    int value64;
    char pad1[4];
    int value6c;
};

struct Game {
    Player *GetPlayerBySlot(int slot);
};

struct Sound {
    void PlayEffectByIndex(int index);
    void PlayTrackIfSelected(int index);
};

struct Object {
    char pad[0x30];
    int state;
    char pad1[0xdc];
    int playerId;

    int GetClampedLevel();
    void PlayStateSound();
};

void Object::PlayStateSound()
{
    Player *player = ((Game *)DAT_0057c670)->GetPlayerBySlot(playerId);
    int value;

    switch (state) {
    case 0x1e:
        DAT_0057ba0c->PlayEffectByIndex(0x28);
        return;
    case 0x17:
        value = player->value64;
        break;
    case 0x1d:
        value = player->value6c;
        break;
    case 0xd:
        value = GetClampedLevel();
        break;
    default:
        return;
    }
    switch (value) {
    case 1:
        DAT_0057ba0c->PlayTrackIfSelected(0x29);
        break;
    case 2:
        DAT_0057ba0c->PlayTrackIfSelected(0x20);
        return;
    case 3:
        DAT_0057ba0c->PlayTrackIfSelected(0x23);
        return;
    }
}
