/* Map_GetTileByte: returns one byte from the 800-byte tile rows (0x489040). */
struct Map {
    char pad[0xa0];
    char *tiles;
    char GetTileByte(int x, int y);
};

char Map::GetTileByte(int x, int y)
{
    int base = *(int *)(tiles + 0x18) + y * 800;

    return *(char *)(base + x);
}
