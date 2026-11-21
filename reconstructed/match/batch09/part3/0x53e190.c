/* Tilemap_GetCell: reads a 16-bit cell from a tile map, returning zero for
   out-of-range coordinates (0x53e190). */
unsigned short Tilemap_GetCell(unsigned int map, int x, int y)
{
    if (x < 0 || x >= (int)*(unsigned short *)(map + 0x1a) ||
        y < 0 || y >= (int)*(unsigned short *)(map + 0x1c))
        return 0;
    return *(unsigned short *)(*(int *)(map + 0x20) * y +
                               *(int *)(map + 0x28) + x * 3);
}
