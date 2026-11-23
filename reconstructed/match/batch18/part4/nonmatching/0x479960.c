/* Map_ComputeBuildableAverage: averages the buildable neighbour count over
   all buildable tiles (0x479960). */
extern "C" int __cdecl Math_RoundFloat(float value);

struct Map {
    int CountBuildableNeighbors(int x, int y, char *tiles);
    void ComputeBuildableAverage(char *tiles);
};

void Map::ComputeBuildableAverage(char *tiles)
{
    int x;
    int y;
    short *p;
    float sum = 0.0f;
    int count = 0;

    p = (short *)(tiles + 0xc);
    x = 0;
    do {
        y = 0;
        do {
            if (*(short *)((char *)p - 8) == 1 && *p == 1 && p[0x140] == 1 && p[0x13c] == 1) {
                count = count + 1;
                sum = (float)CountBuildableNeighbors(x, y, tiles) + sum;
            }
            y = y + 1;
            p = p + 4;
        } while (y < 0x50);
        x = x + 1;
    } while (x < 0x50);
    if (count < 1) {
        *(int *)((char *)this + 0x1860) = 0;
    } else {
        *(int *)((char *)this + 0x1860) = (int)Math_RoundFloat(sum / (float)count);
    }
    if (*(int *)((char *)this + 0x1860) < 0) {
        *(int *)((char *)this + 0x1860) = 0;
    }
    if (8 < *(int *)((char *)this + 0x1860)) {
        *(int *)((char *)this + 0x1860) = 8;
    }
}
