/* BuildingValue_ConstructDefault (0x4e4340, 46 bytes).
   Build: /O2 /TP.  Default value -1 in field 0xc, remaining fields cleared. */
extern int DAT_0055c5a4;

struct Game {
    void SetHQLevel(int level);
};

struct BuildingValue {
    BuildingValue *ConstructDefault(int level);
};

BuildingValue *BuildingValue::ConstructDefault(int level)
{
    *(int **)this = &DAT_0055c5a4;
    ((Game *)this)->SetHQLevel(level);
    *(int *)((char *)this + 0xc) = -1;
    *(int *)((char *)this + 0x10) = 0;
    *(int *)((char *)this + 0x14) = 0;
    *(int *)((char *)this + 0x18) = 0;
    *(char *)((char *)this + 0x1c) = 0;
    return this;
}
