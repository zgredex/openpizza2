/* Player_MissionState_Construct: installs the mission-state vtable and loads
   either the supplied source or the default date state (0x4f5df0).
   Build: /O2 /TP. */
struct Player_MissionState {
    void *vtable;
    Player_MissionState(void *source);
    void Load(void *source);
};

struct Game {
    void InitDateState();
};

Player_MissionState::Player_MissionState(void *source)
{
    *(void **)this = (void *)0x55c5e8;
    if (source != 0)
        Load(source);
    else
        ((Game *)this)->InitDateState();
}
