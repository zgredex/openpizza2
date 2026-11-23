extern "C" char DAT_00571be4[];

struct Array {
    void *GetRecord28(int a, int b);
};

extern "C" void NoOp_Stub(char *message);

struct Map {
    void LinkCells(int a, int b, int c, int unused);
};

void Map::LinkCells(int a, int b, int c, int unused)
{
    char *first = (char *)((Array *)this)->GetRecord28(a, b);
    char *second = (char *)((Array *)this)->GetRecord28(a, c);
    int firstValue = *(int *)(first + 0xc);
    int secondValue = *(int *)(second + 0xc);
    double slope;

    if (firstValue == secondValue) {
        slope = 0.0;
    } else {
        slope = (double)(*(int *)(first + 0x10) - *(int *)(second + 0x10)) /
                (double)(firstValue - secondValue);
        if (slope == 0.5 || slope == -0.5)
            goto add;
    }
    if (firstValue != secondValue && slope != 0.0) {
        NoOp_Stub(DAT_00571be4);
        return;
    }
add:
    {
        short *edges = (short *)(first + 0x14);
        short *edge = edges;
        int i = 0;

        do {
            if (*edge == c)
                return;
            i++;
            edge++;
        } while (i < 8);
        i = 0;
        do {
            if (*edges == -1) {
                *(short *)(first + 0x14 + i * 2) = (short)c;
                break;
            }
            i++;
            edges++;
        } while (i < 8);
    }
    if (a == 1) {
        short *edges = (short *)(second + 0x14);
        short *edge = edges;
        int i = 0;

        do {
            if (*edge == b)
                return;
            i++;
            edge++;
        } while (i < 8);
        i = 0;
        while (*edges != -1) {
            i++;
            edges++;
            if (i > 7)
                return;
        }
        *(short *)(second + 0x14 + i * 2) = (short)b;
    }
}
