// Game_GetPlanName: switch returning fixed string addresses.

extern char DAT_0057266c[];
extern char DAT_0057265c[];
extern char DAT_00572648[];
extern char DAT_0057263c[];
extern char DAT_00572630[];
extern char DAT_0057261c[];
extern char DAT_00572608[];
extern char DAT_005725f4[];
extern char DAT_005725dc[];
extern char DAT_005725c8[];
extern char DAT_005725c0[];
extern char DAT_005725ac[];
extern char DAT_00572598[];
extern char DAT_00572584[];
extern char DAT_00572570[];
extern char DAT_00572564[];
extern char DAT_0057255c[];
extern char DAT_00572548[];
extern char DAT_00572538[];
extern char DAT_00572524[];
extern char DAT_0057250c[];
extern char DAT_005724f4[];
extern char DAT_005724e4[];
extern char DAT_005724cc[];
extern char DAT_005724bc[];

struct GamePlan {
    char *GetPlanName(int plan);
};

char *GamePlan::GetPlanName(int plan)
{
    switch (plan) {
    case 0:
        return DAT_0057266c;
    case 3:
        return DAT_0057265c;
    case 0x18:
        return DAT_00572648;
    case 1:
        return DAT_0057263c;
    case 4:
        return DAT_00572630;
    case 5:
        return DAT_0057261c;
    case 6:
        return DAT_00572608;
    case 7:
        return DAT_005725f4;
    case 8:
        return DAT_005725dc;
    case 0xb:
        return DAT_005725c8;
    case 9:
        return DAT_005725c0;
    case 0xa:
        return DAT_005725ac;
    case 0xc:
        return DAT_00572598;
    case 0xd:
        return DAT_00572584;
    case 0xe:
        return DAT_00572570;
    case 0xf:
        return DAT_00572564;
    case 0x10:
        return DAT_0057255c;
    case 0x11:
        return DAT_00572548;
    case 0x12:
        return DAT_00572538;
    case 0x13:
        return DAT_00572524;
    case 0x14:
        return DAT_0057250c;
    case 0x15:
        return DAT_005724f4;
    case 0x16:
        return DAT_005724e4;
    case 0x17:
        return DAT_005724cc;
    default:
        return DAT_005724bc;
    }
}
