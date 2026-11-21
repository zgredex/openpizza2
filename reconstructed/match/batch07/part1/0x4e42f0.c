/* BuildingValue_Construct (0x4e42f0, 46 bytes).
   Build: /O2 /TP.  Vtable store, level setup, then field clears. */
extern int DAT_0055c5a4;

struct Game {
    void SetHQLevel(int level);
};

struct BuildingValue {
    BuildingValue *Construct(int level, int value);
};

BuildingValue *BuildingValue::Construct(int level, int value)
{
    *(int **)this = &DAT_0055c5a4;
    ((Game *)this)->SetHQLevel(level);
    *(int *)((char *)this + 0x10) = 0;
    *(int *)((char *)this + 0x14) = 0;
    *(int *)((char *)this + 0x18) = 0;
    *(char *)((char *)this + 0x1c) = 0;
    *(int *)((char *)this + 0xc) = value;
    return this;
}
