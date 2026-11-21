/* Record_GetScreenRect48 (0x5340d0): converts an entry of the 0x48-byte
   screen table into pixel coordinates using the tile-position tables. */
struct ScreenRecord {
    int index;                 /* 0x00 */
    char pad[0x32 - 4];
    short tile;                /* 0x32 */
    char pad2[0x48 - 0x34];
};

struct ScreenTable {
    char pad[0x28];
    unsigned short *tilesX;    /* 0x28 */
    unsigned short *tilesY;    /* 0x2c */
    char pad2[0x4c - 0x30];
    ScreenRecord *records;     /* 0x4c */
    char *positions;           /* 0x50 */
    void GetScreenRect(int entry, int *x, int *y);
};

void ScreenTable::GetScreenRect(int entry, int *x, int *y)
{
    ScreenRecord *record;
    unsigned short tileX;
    unsigned short tileY;

    record = (ScreenRecord *)((char *)records + entry * 0x48);
    tileX = tilesX[record->tile];
    *x = tileX +
         (int)((double (*)[19])(positions + 0x70))[record->index][0];
    tileY = tilesY[records[entry].tile];
    *y = tileY +
         (int)((double (*)[19])(positions + 0x78))[records[entry].index][0];
}
