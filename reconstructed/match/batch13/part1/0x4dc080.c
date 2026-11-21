/* Mission_ApplySettings (0x4dc080). */
struct Mission {
    char pad0[0x48];
    int field48;            /* 0x48 */
    char pad1[0x2f8];       /* to 0x344 */
    int field344;           /* 0x344 */
    char pad2[4];
    int field34c;           /* 0x34c */
    int field350;           /* 0x350 */
    int field354;           /* 0x354 */
    int field358;           /* 0x358 */
    int field35c;           /* 0x35c */
    int field360;           /* 0x360 */
};
extern int DAT_0057bb24;
extern int DAT_0057bb28;
extern int DAT_0057bb2c;
extern int DAT_0057bb30;
extern char DAT_0057bb34;
extern int DAT_0057bb38;
extern char DAT_0057bb3c;
extern int DAT_0057bb48;
extern int DAT_0057bb4c;
extern int DAT_0057bb50;

void __fastcall Mission_ApplySettings(Mission *mission)
{
    DAT_0057bb24 = mission->field344;
    DAT_0057bb28 = mission->field48;
    DAT_0057bb2c = mission->field34c;
    DAT_0057bb30 = mission->field35c;
    DAT_0057bb34 = 1;
    DAT_0057bb38 = mission->field360;
    DAT_0057bb3c = 1;
    DAT_0057bb48 = mission->field350;
    DAT_0057bb4c = mission->field354;
    DAT_0057bb50 = mission->field358;
}
