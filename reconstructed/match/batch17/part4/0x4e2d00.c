struct IDMap {
    int unused;
    int **Lookup(int index, int *out);
};

struct Game {
    int CountObjectsByType(int type);
};

struct Rating {
    int ClampAdjusted();
    int AdjustA();
};

struct Player {
    char pad0[0x148];
    IDMap map;
    char pad1[0x15c - 0x14c];
    int count;
    int ComputeAverageRating();
};

int Player::ComputeAverageRating()
{
    int sum = 0;
    int total = 0;
    int i = 0;
    if (0 < *(int *)((char *)this + 0x15c)) {
        do {
            void *player = ((IDMap *)((char *)this + 0x148))->Lookup(i, 0);
            int count = ((Game *)player)->CountObjectsByType(-1);
            total = total + count;
            int j = 0;
            if (0 < count) {
                do {
                    int **record = ((IDMap *)((char *)player + 0x1500))->Lookup(j, 0);
                    int value = ((Rating *)*record)->ClampAdjusted();
                    sum = sum + value;
                    value = ((Rating *)*record)->AdjustA();
                    sum = sum + value;
                    j++;
                } while (j < count);
            }
            i++;
        } while (i < *(int *)((char *)this + 0x15c));
        if (sum != 0 && total != 0)
            return sum / total;
    }
    return 0;
}
