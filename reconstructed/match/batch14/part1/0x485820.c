/* Game_UpdateAmbientLight (0x485820): updates the ambient-light level from
   the current sky colour and reports whether it changed. */
extern int DAT_00585518;

struct Game {
    char pad[0x94];
    unsigned char *sky;        /* 0x94 */
    char pad2[0x2db0 - 0x98];
    int low[1];                /* 0x2db0 */
    int high[1];               /* 0x2db4 */
    int UpdateAmbientLight(void *weather);
};

int Game::UpdateAmbientLight(void *weather)
{
    int red;
    int green;
    int level;
    int scaled;

    red = sky[7];
    green = sky[6];
    scaled = green * 5;
    if (*(int *)((char *)weather + 0xc) == 0x10) {
        level = 0xf8;
    } else {
        level = (low[red] * (0x3c - scaled) + high[red] * scaled) / 0x3c;
    }
    if (DAT_00585518 != level) {
        DAT_00585518 = level;
        return 1;
    }
    return 0;
}
