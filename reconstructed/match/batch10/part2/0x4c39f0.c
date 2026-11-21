/* GamePlan_UpdateEffectBars: fill the eight game-plan category effect
   bars (0x4c39f0). */
extern "C" int DAT_0057da14;
extern "C" int DAT_00582858;

struct GamePlan {
    int ComputeCategoryEffect(int value, int index);
};

struct Math {
    int PiecewiseLinear(int value);
};

extern "C" void Rating_UpdateBarByKey(void *menu, int id, int index,
                                      int value, int colour);

extern "C" void GamePlan_UpdateEffectBars(void *menu, void *plan)
{
    int index;

    for (index = 0; index < 8; index++) {
        int effect = ((struct GamePlan *)DAT_0057da14)->ComputeCategoryEffect(
            *(int *)((char *)plan + 0x48), index);

        effect = ((struct Math *)DAT_0057da14)->PiecewiseLinear(effect);
        Rating_UpdateBarByKey(menu, 0x509, index, effect, DAT_00582858);
    }
}
