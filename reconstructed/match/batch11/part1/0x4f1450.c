/* Building_HasAdjacentTile: scans the eight linked cells of a tile and
   reports whether one resolves to the requested record (0x4f1450). */
struct Tile {
    char pad[0x14];
    short cells[8];
};

struct ArrayHelper {
    void *GetRecord28(int index, int value);
};

struct Building {
    int HasAdjacentTile(int index, Tile *tile, int target);
};

int Building::HasAdjacentTile(int index, Tile *tile, int target)
{
    int i;

    for (i = 0; i < 8; i++) {
        short value = tile->cells[i];

        if (value != -1) {
            if (((ArrayHelper *)this)->GetRecord28(index, value) == (void *)target)
                return 1;
        }
    }
    return 0;
}
