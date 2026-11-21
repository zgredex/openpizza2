/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
struct GamePlan {
    int ComputeCategoryEffect(int category, int index);
};

struct MissionGoal {
    void AppendCommandIfActive(int command, int arg);
    void HandleEvent(int command, int arg1, int arg2);
};

extern "C" int *g_game;         /* 0x57c670 */
extern "C" int *g_gamePlan;     /* 0x57c9ec */

extern "C" void __cdecl Mission_CheckGamePlanCategoryGoal(void)
{
    int i;
    int record;
    int category;
    int effect;

    record = *(int *)((int)g_game + 0x200 + *(int *)((int)g_game + 0x2ec) * 4);
    for (i = 0; i < 7; i++) {
        category = *(int *)(record + 0x48);
        effect = ((GamePlan *)g_gamePlan)->ComputeCategoryEffect(category, i);
        if (effect > 0x46) {
            ((MissionGoal *)*(void **)(*(int *)((int)g_game + 0x224) + 0xa8))
                ->AppendCommandIfActive(0x1a, -1);
            ((MissionGoal *)*(void **)(*(int *)((int)g_game + 0x224) + 0xa8))
                ->HandleEvent(0x1a, -1, -1);
            return;
        }
    }
}
