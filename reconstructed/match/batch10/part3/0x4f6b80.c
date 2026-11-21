/* Mission_TickGoalDeadline: count down a mission goal deadline. */
struct Mission {
    void TickGoalDeadline(int param);
    void EvaluateGoals(int param, char flag);
};

extern "C" void __fastcall Game_CompleteMissionStage(void *mission);

void Mission::TickGoalDeadline(int param)
{
    if (*(char *)((char *)this + 0xcc) == 0) {
        *(int *)((char *)this + 0xc0) = *(int *)((char *)this + 0xc0) - 1;
        EvaluateGoals(param, 0);
        if (*(int *)((char *)this + 0xc0) == 0 &&
            *(char *)((char *)this + 0xcc) == 0)
            Game_CompleteMissionStage(this);
    }
}
