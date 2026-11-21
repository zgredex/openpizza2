/* Non-matching candidate.
   First difference: offset 0xe, 109 bytes differ.
   original returns inline on the null record; candidate jumps to a shared epilogue.
   Kept for evidence; not part of the strict match set. */
struct Map {
    char pad0[0xf8];
    int offset_x;
    int offset_y;
    int ComputeBlitRect(int x, int y, int *mode, int flags);
};

struct RecordData {
    void GetTwoFloats48(int index, int *first, int *second);
};

struct MapObject {
    char pad0[0xc4];
    Map *map;
    int *record;
    void ComputeBlitRect();
};

void MapObject::ComputeBlitRect()
{
    if (record == 0)
        return;
    int first;
    int second;
    ((RecordData *)*(void **)((char *)record + 0x58))
        ->GetTwoFloats48(record[0], &first, &second);
    if (record[1] == -1) {
        map->ComputeBlitRect(first + 0xa0, second + 0xd0, (int *)1, 0);
        return;
    }
    Map *m = *(Map **)((char *)this + 0xc4);
    m->ComputeBlitRect(*(int *)((char *)m + 0xf8) + second,
                       *(int *)((char *)m + 0xfc) + first, (int *)1, 0);
}
