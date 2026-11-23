/* Map_DrawRecordLinkSprites: draws the eight link sprites of one record
   (0x4edbf0). */
struct Object {
    void GetBufferPair(int buffer, int **base, int *ioValue, int *zero1,
                       int *zero2);
};

extern "C" void Surface_BlitFormat(int surface, int x1, int y1, int x2, int y2,
                                   unsigned int color1, unsigned int color2,
                                   char flag);

class Map {
public:
    void DrawRecordLinkSprites(int buffer, void *record);
};

void Map::DrawRecordLinkSprites(int param_1, void *param_2)
{
    short sVar1;
    short *psVar2;
    int *local_10;
    unsigned int local_c;
    unsigned int local_8;
    int local_4;
    int count;

    ((Object *)this)->GetBufferPair(param_1, &local_10, &local_4, (int *)&local_8,
                                    (int *)&local_c);
    count = 8;
    psVar2 = (short *)((char *)param_2 + 0x14);
    do {
        sVar1 = *psVar2;
        if (sVar1 != -1) {
            Surface_BlitFormat(
                *(int *)((char *)this + 8),
                *(int *)((char *)param_2 + 0xc) - *(int *)((char *)this + 0x24),
                *(int *)((char *)param_2 + 0x10) - *(int *)((char *)this + 0x28),
                *(int *)(*local_10 + sVar1 * 0x28 + 0xc) -
                    *(int *)((char *)this + 0x24),
                *(int *)(*local_10 + 0x10 + sVar1 * 0x28) -
                    *(int *)((char *)this + 0x28),
                local_8, local_c, '\x01');
        }
        psVar2 = psVar2 + 1;
        count = count + -1;
    } while (count != 0);
}
