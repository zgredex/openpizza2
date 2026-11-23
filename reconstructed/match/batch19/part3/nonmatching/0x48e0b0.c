/* Game_CacheCurrentCityGlobals (0x48e0b0). */

struct City {
    char pad0[4];
    City *owner;                /* 0x04 */
    char pad1[0x24];
    int a2c;                    /* 0x2c */
    int a30;                    /* 0x30 */
    char pad2[8];
    int v3c;                    /* 0x3c */
    int v40;                    /* 0x40 */
    int v44;                    /* 0x44 */
    int v48;                    /* 0x48 */
    int v4c;                    /* 0x4c */
    int v50;                    /* 0x50 */
    int v54;                    /* 0x54 */
    int v58;                    /* 0x58 */
    int v5c;                    /* 0x5c */
    int v60;                    /* 0x60 */
    int v64;                    /* 0x64 */
    int v68;                    /* 0x68 */
    int copy[6];                /* 0x6c */
};

struct Game {
    char pad0[0x94];
    char *state;                /* 0x94 */
    char pad1[0x168];
    void *companies[1];         /* 0x200 */
    char pad2[0xe8];
    int companyIndex;           /* 0x2ec */

    City *GetPlayerCity();
    void CacheCurrentCityGlobals();
};

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
extern short DAT_0057c24c;
extern char DAT_0057c24e;
extern int DAT_0057c250;

void Game::CacheCurrentCityGlobals()
{
    City *city = ((Game *)companies[companyIndex])->GetPlayerCity();

    DAT_0057c1f8 = city->v3c;
    DAT_0057c1fc = city->v40;
    DAT_0057c200 = city->v44;
    DAT_0057c204 = city->v48;
    DAT_0057c208 = city->v4c;
    DAT_0057c20c = city->v50;
    DAT_0057c210 = city->v54;
    DAT_0057c214 = city->v58;
    DAT_0057c218 = city->v5c;
    DAT_0057c21c = city->v60;
    DAT_0057c220 = city->v64;
    DAT_0057c224 = city->v68;
    DAT_0057c240 = city->a2c;
    DAT_0057c244 = city->a30;
    DAT_0057c248 = city->owner->v40;
    DAT_0057c24c = *(short *)(state + 4);
    DAT_0057c24e = *(char *)(state + 8);
    DAT_0057c250 = *(unsigned char *)(state + 7);

    int *dst = &DAT_0057c228;
    int *src = city->copy;
    do {
        *dst++ = *src++;
    } while ((int)dst < 0x57c240);
}
