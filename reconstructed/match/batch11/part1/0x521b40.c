/* UI_Sprite_BeginAnimation: registers the sprite with the effect host on the
   first start and always stores the animation range (0x521b40). */
struct EffectHost {
    void AddEffectObject(void *object);
};

struct Sprite {
    char pad[0x8];
    int *owner;
    char pad2[0x40];
    int started;
    char pad3[0x20];
    int rangeStart;
    int rangeEnd;
    char pad4[0x24];
    int time;

    void BeginAnimation(int unused, int start, int end);
};

void Sprite::BeginAnimation(int unused, int start, int end)
{
    EffectHost *host = *(EffectHost **)(*(int *)((char *)this + 8) + 0x134);

    if (started == 0) {
        time = 0;
        host->AddEffectObject(this);
        started = 1;
        rangeEnd = end;
        rangeStart = start;
        return;
    }
    rangeEnd = end;
    rangeStart = start;
}
