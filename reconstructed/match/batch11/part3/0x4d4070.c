struct UI {
    void SetChildState(int state);
};
struct CS {
    void Enter();
    void Leave();
};
struct World {
    char pad[0x240];
    struct CS *cs;
};
extern int DAT_0057c670;
struct Game {
    char pad[0x825];
    char openState;

    struct UI *GetRecordByField814();
    void SetRecordOpenState(char state);
};
void Game::SetRecordOpenState(char state)
{
    struct UI *record;

    openState = state;
    record = GetRecordByField814();
    if (record != 0) {
        ((struct World *)DAT_0057c670)->cs->Enter();
        if (openState == 1)
            record->SetChildState(0x11);
        else
            record->SetChildState(0x10);
        ((struct World *)DAT_0057c670)->cs->Leave();
    }
}
