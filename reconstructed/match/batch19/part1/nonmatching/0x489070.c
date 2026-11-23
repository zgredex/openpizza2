// Rating_GetFloat: computes a category rating from difficulty and a value.

extern "C" int g_FreePlayDifficulty;

extern char DAT_0055c328[];
extern char DAT_0055c32c[];
extern char DAT_0055c45c[];
extern char DAT_0055c460[];
extern char DAT_0055c464[];
extern char DAT_0055c468[];
extern char DAT_0055c46c[];
extern char DAT_0055c470[];

float __stdcall Rating_GetFloat(int object, int type)
{
    float value = *(float *)(object + 0x98);
    int level = 0xb - g_FreePlayDifficulty;
    float base = (float)level * *(float *)DAT_0055c32c;

    switch (type) {
    case 0:
        return value * *(float *)DAT_0055c470 + base + *(float *)DAT_0055c46c;
    case 1:
        return value * *(float *)DAT_0055c46c + base + *(float *)DAT_0055c468;
    case 2:
        return value * *(float *)DAT_0055c46c + base + *(float *)DAT_0055c464;
    case 3:
        return value * *(float *)DAT_0055c470 + base + *(float *)DAT_0055c464;
    case 4:
        return value * *(float *)DAT_0055c460 + base + *(float *)DAT_0055c328;
    case 5:
    case 8:
        return value * *(float *)DAT_0055c328 + base + *(float *)DAT_0055c464;
    case 6:
        return value * *(float *)DAT_0055c470 + base + *(float *)DAT_0055c460;
    case 7:
        return base + *(float *)DAT_0055c45c;
    }
    return base;
}
