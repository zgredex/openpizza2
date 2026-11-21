/* Stats_GetAverageValue: average of an edge-matched tile count over players
   (0x4795e0). */
struct Map {
    int CountEdgeMatchedTiles(int type);
};

struct Game {
    int CountPlayersByByte(int type);
};

struct Stats {
    char pad[0x1864];
    int average;
    void GetAverageValue(int type);
};

void Stats::GetAverageValue(int type)
{
    int total = ((struct Map *)this)->CountEdgeMatchedTiles(type);
    int count = ((struct Game *)this)->CountPlayersByByte(2);

    if (count > 0) {
        average = total / count;
    } else {
        average = 0;
    }
}
