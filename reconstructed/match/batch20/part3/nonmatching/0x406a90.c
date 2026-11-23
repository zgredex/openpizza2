extern int DAT_0057b8a8[];
extern int DAT_0057b9ac[];
extern int DAT_0057b9b4[];
extern int DAT_0057b9c4[];
extern int DAT_0057b9f0;
extern int DAT_0057b9f4;
extern int DAT_0057b9f8;
extern int DAT_0057b9fc;
extern int DAT_0057b938;
extern int DAT_0057b93c;
extern int DAT_0057b940;
extern int DAT_0057b944;
extern int DAT_0057b948;
extern int DAT_0057b964;
extern int DAT_0057b968;
extern int DAT_0057b96c;
extern int DAT_0057b970;
extern int DAT_0057b978;
extern int DAT_0057b9c8;
extern int DAT_0057b9cc;
extern int DAT_0057b9d0;
extern int DAT_0057b9d4;
extern int DAT_0057b9d8;
extern int DAT_0057b9dc;
extern int DAT_0058557c;
extern int DAT_00585580;
extern int DAT_00585584;
extern int DAT_00585588;

extern "C" int Random_RangeFast(int low, int high);

int Settings_LoadFromRegistry();

void Settings_InitDefaults()
{
    int i;
    int *entry;

    for (i = 0; i < 0x59; i++)
        DAT_0057b8a8[i] = 0;
    if (Settings_LoadFromRegistry() == 0) {
        DAT_0057b9f0 = 5;
        DAT_0057b9f8 = 4;
        DAT_0057b9fc = 0;
        DAT_0057b9f4 = 0;
        DAT_0057b938 = Random_RangeFast(0, 1);
        DAT_0057b93c = Random_RangeFast(0, DAT_0058557c - 1);
        DAT_0057b940 = Random_RangeFast(0, DAT_00585580 - 1);
        DAT_0057b944 = Random_RangeFast(0, DAT_00585584 - 1);
        DAT_0057b948 = Random_RangeFast(0, DAT_00585588 - 1);
        DAT_0057b9c8 = 0xfa;
        DAT_0057b9d0 = -1;
        DAT_0057b9d4 = -1;
        DAT_0057b9d8 = -1;
        DAT_0057b9cc = 0xb;
        DAT_0057b964 = 1;
        DAT_0057b968 = 0;
        DAT_0057b96c = 1;
        DAT_0057b970 = 1;
        DAT_0057b9dc = 3;
        DAT_0057b978 = 6;
        for (entry = DAT_0057b9ac; (int)entry < (int)DAT_0057b9c4; entry++) {
            entry[-0xc] = 100;
            entry[-6] = 0;
            *entry = (int)entry < (int)DAT_0057b9b4;
        }
    }
}
