/* GamePlan_SetActiveEffect: stores the active effect id and its computed
   effect value (0x50fb70).  Build: /O2 /TP. */
struct GamePlan {
    char pad[4];
    int effect;
    char pad2[0x20];
    int effectValue;
    int ComputeEffectValue(int param);
    void SetActiveEffect(int effect, int value);
};

void GamePlan::SetActiveEffect(int newEffect, int value)
{
    if (newEffect == 0) {
        effect = 0;
        return;
    }
    effectValue = ComputeEffectValue(value);
    effect = newEffect;
}
