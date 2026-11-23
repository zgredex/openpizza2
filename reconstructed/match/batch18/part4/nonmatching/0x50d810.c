extern char *DAT_0057c670;
extern float DAT_0055c320;

/* UI_UpdateValueBar: decays a value bar by the level modifier of two objects
   (0x50d810). */
struct Object {
    int GetLevelProperty(int property);
};

struct Economy {
    int GetModifier(int type, int property);
};

struct Game {
    void *GetPlayerBySlot(int slot);
};

struct UI {
    void SetChildHeightFromValue();
    void UpdateValueBar(void *other, int refresh);
};

void UI::UpdateValueBar(void *other, int refresh)
{
    int modifier;
    int other_modifier;
    int value;

    if (*(int *)((char *)this + 0x30) != 0xd) {
        void *player = ((Game *)DAT_0057c670)->GetPlayerBySlot(*(int *)((char *)this + 0x110));

        if (player == 0) {
            return;
        }
        modifier = ((Economy *)player)->GetModifier(*(int *)((char *)this + 0x30), 2);
    } else {
        modifier = ((Object *)this)->GetLevelProperty(2);
    }
    if (*(int *)((char *)other + 0x30) != 0xd) {
        void *player = ((Game *)DAT_0057c670)->GetPlayerBySlot(*(int *)((char *)other + 0x110));

        if (player == 0) {
            return;
        }
        other_modifier = ((Economy *)player)->GetModifier(*(int *)((char *)other + 0x30), 1);
    } else {
        other_modifier = ((Object *)other)->GetLevelProperty(1);
    }
    if (modifier == 0) {
        value = 100;
    } else {
        value = (int)(DAT_0055c320 / (float)modifier * (float)other_modifier);
    }
    if (*(int *)((char *)this + 0xa8) <= value) {
        *(int *)((char *)this + 0xa8) = 0;
        return;
    }
    value = *(int *)((char *)this + 0xa8) - value;
    *(int *)((char *)this + 0xa8) = value;
    if (value < 0) {
        *(int *)((char *)this + 0xa8) = 0;
    }
    if (refresh == 0) {
        SetChildHeightFromValue();
    }
}
