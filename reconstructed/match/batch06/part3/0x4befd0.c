/* GangsterWeaponPanel_RefreshWithSound: plays the refresh sound and fills the
   unit details of the current gangster weapon panel (0x4befd0).
   Build: /O2 /TP. */
struct Unit {
    char pad[0x30];
    int field30;
};

struct Player {
    char pad[0x21c];
    Unit *unit;
};

struct Sound {
    void ProcessEvent(int value, int a, int b);
};

void __cdecl CriminalsPage_FillUnitDetails(int panel);

void GangsterWeaponPanel_RefreshWithSound(int panel)
{
    Player *player = *(Player **)0x57c670;
    Sound *sound = *(Sound **)0x57ba0c;

    sound->ProcessEvent(player->unit->field30, 0, 1);
    CriminalsPage_FillUnitDetails(panel);
}
