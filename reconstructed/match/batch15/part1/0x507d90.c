/* Person_AdvanceRoute: advances a person's route or rebuilds the path to its
   target (0x507d90). */
extern int *DAT_0057c670;

struct CS {
    void Enter();
    void Leave();
};

struct Route {
    char pad[0x20];
    int vehicle;
    char pad1[4];
    short state;
};

struct Person {
    char pad[0xc8];
    Route *route;

    int IsVisibleThisFrame();
    int PathToTileAndStep(int step, int param);
    int RecomputePathStep(int param);
    int AdvanceRoute(int param);
};

int Person::AdvanceRoute(int param)
{
    int step;

    if (route == 0) {
        return 0;
    }
    (*(struct CS **)((char *)DAT_0057c670 + 0x240))->Enter();
    step = route ? route->vehicle : 0;
    if (IsVisibleThisFrame() == 0 || route->state == -1) {
        step = PathToTileAndStep(step, param);
    } else {
        step = RecomputePathStep(param);
    }
    (*(struct CS **)((char *)DAT_0057c670 + 0x240))->Leave();
    return step;
}
