// PlayerCompany_InitDefaults @ 0x50f590 (157 bytes)
// Restores the cached city globals into a fresh player company record.

extern int DAT_0057c1f8;
extern int DAT_0057c1fc;
extern int DAT_0057c200;
extern int DAT_0057c204;
extern int DAT_0057c208;
extern int DAT_0057c20c;
extern int DAT_0057c210;
extern int DAT_0057c214;
extern int DAT_0057c218;
extern int DAT_0057c21c;
extern int DAT_0057c220;
extern int DAT_0057c224;
extern int DAT_0057c228;
extern int DAT_0057c240;
extern int DAT_0057c244;
extern int DAT_0057c248;

class PlayerCompany {
public:
    char pad00[4];
    char *state;            // 0x04
    char pad08[0x24];
    int f2c;                // 0x2c
    int f30;                // 0x30
    char pad34[8];
    int f3c;                // 0x3c
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int copy[6];            // 0x6c

    void InitDefaults();
};

void PlayerCompany::InitDefaults()
{
    f3c = DAT_0057c1f8;
    f40 = DAT_0057c1fc;
    f44 = DAT_0057c200;
    f48 = DAT_0057c204;
    f4c = DAT_0057c208;
    f50 = DAT_0057c20c;
    f54 = DAT_0057c210;
    f58 = DAT_0057c214;
    f5c = DAT_0057c218;
    f60 = DAT_0057c21c;
    f64 = DAT_0057c220;
    f68 = DAT_0057c224;
    f2c = DAT_0057c240;
    f30 = DAT_0057c244;
    *(int *)(state + 0x40) = DAT_0057c248;

    int *src = &DAT_0057c228;
    int i = 0;
    do {
        copy[i++] = *src++;
    } while ((int)src < 0x57c240);
}
