/* GamePlan_Construct: constructs a game plan with default fields
   (0x50f630). */
struct GamePlan {
    void **vtable;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    GamePlan();
};

GamePlan::GamePlan()
{
    vtable = (void **)0x55c688;
    f4 = 0;
    f8 = 2;
    f10 = 0;
    f14 = 0;
    f18 = 0;
    f1c = -1;
    f20 = 0;
    f2c = -1;
    fc = -1;
    f24 = 0;
    f28 = 0;
}
