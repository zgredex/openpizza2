/* Map_SetTileFieldWithDefault (0x4ed330, 46 bytes).  Build: /O2 /TP.
   A tile field of 0xffffffff means "use the default byte from the tile row". */
struct Array {
    void SetField4Stride12(int map, unsigned value, int index);
};

struct Map {
    void SetTileFieldWithDefault(int map, int index, unsigned value);
};

void Map::SetTileFieldWithDefault(int map, int index, unsigned value)
{
    if (value == 0xffffffff)
        value = *(unsigned char *)(*(int *)((char *)this + 4) + 0x24 + index * 0x48);
    ((Array *)this)->SetField4Stride12(map, value, index);
}
