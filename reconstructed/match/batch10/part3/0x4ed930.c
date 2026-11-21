/* Map_SetHoverTile: copy a hover descriptor into the map's cached record. */
typedef struct {
    int values[15];
} HoverBulk;

typedef struct {
    HoverBulk bulk;
} HoverRecord;

typedef struct {
    int x;
    int y;
    HoverRecord *record;
} HoverSource;

struct Map {
    char pad[0x64];
    HoverSource *hover;
    int field68;
    void SetHoverTile(HoverSource *source);
};

void Map::SetHoverTile(HoverSource *source)
{
    hover->x = source->x;
    hover->y = source->y;
    hover->record->bulk = source->record->bulk;
    *(int *)((char *)hover->record + 4) = field68;
    *(int *)((char *)hover->record + 0x10) = field68;
}
