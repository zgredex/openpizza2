extern float DAT_0057ba00;

struct Game {
    char pad[0x2fc];
    int *state;
    char pad2[0x2db0 - 0x300];
    int curve[25];
    int RefreshDaylightCurve(float t);
};

int Game::RefreshDaylightCurve(float t)
{
    int table[25] = {
        0x46, 0x46, 0x49, 0x50, 0x5f, 0x78, 0xc8, 0xe1, 0xf0,
        0xf8, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xf8, 0xf0, 0xe1,
        0xc8, 0x78, 0x5f, 0x50, 0x49, 0x46, 0x46
    };
    int i;

    DAT_0057ba00 = t;
    for (i = 0; i < 25; i++)
        curve[i] = (int)(table[i] + (0xfb - table[i]) * t);
    if (state != 0)
        *(int *)((char *)state + 0xf4) = 1;
    return 1;
}
