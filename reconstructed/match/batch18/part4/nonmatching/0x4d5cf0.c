/* Map_CountNearbyObjects: counts nearby map objects by category and reports
   whether a 0x20 object is close (0x4d5cf0). */
struct Game {
    int GetObjectCenterY();
    int GetObjectBottom();
};

struct IDMap {
    void *Lookup(int index, int *unused);
};

struct Map {
    char pad[0xfac];
    char map[0x14];
    int fieldfc0;
    void CountNearbyObjects(void *object, int *out2, int *out3, int *out4);
};

void Map::CountNearbyObjects(void *object, int *out2, int *out3, int *out4)
{
    int n = fieldfc0;
    int center_y;
    int bottom;
    int i;

    *out3 = 0;
    *out2 = 0;
    *out4 = 0;
    center_y = ((Game *)object)->GetObjectCenterY();
    bottom = ((Game *)object)->GetObjectBottom();
    i = 0;
    if (0 < n) {
        do {
            void *other = ((IDMap *)((char *)this + 0xfac))->Lookup(i, 0);
            int other_y = ((Game *)other)->GetObjectCenterY();
            int other_bottom = ((Game *)other)->GetObjectBottom();

            if ((center_y - other_y) * (center_y - other_y) +
                (bottom - other_bottom) * (bottom - other_bottom) * 4 < 360000) {
                if (*(int *)((char *)other + 4) == 0) {
                    *out2 = *out2 + 1;
                } else if (*(int *)((char *)other + 4) == 0x20) {
                    *out4 = 1;
                } else if (*(int *)((char *)other + 0x48) != -1) {
                    *out3 = *out3 + 1;
                }
            }
            i = i + 1;
        } while (i < n);
    }
}
