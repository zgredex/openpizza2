/* Map_ClampScrollY (0x4ed3c0): clamps the vertical map scroll offset and
   reports whether it changed. */
extern int DAT_0057c670;

struct Map {
    char pad[0x30];
    int height;                /* 0x30 */
    char pad2[0x38 - 0x34];
    int originY;               /* 0x38 */
    char pad3[0xec - 0x3c];
    int scrollY;               /* 0xec */
    char pad4[0x10170 - 0xf0];
    int viewTop;               /* 0x10170 */
    int viewHeight;            /* 0x10174 */
    int ClampScrollY(int value);
};

int Map::ClampScrollY(int value)
{
    int previous;
    int minimum;
    int limit;

    previous = scrollY;
    scrollY = value;
    minimum = height - viewHeight;
    if (value < minimum) {
        scrollY = minimum;
    }
    if (*(int *)(DAT_0057c670 + 0x2da0) == 2) {
        limit = viewTop - 0x38 + originY;
        if (scrollY <= limit) {
            goto done;
        }
    } else {
        limit = originY + viewTop;
        if (scrollY <= limit) {
            goto done;
        }
    }
    scrollY = limit;
done:
    return previous != scrollY;
}
