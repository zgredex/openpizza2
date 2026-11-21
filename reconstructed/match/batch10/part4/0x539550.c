/* Surface_ClearRows (0x539550): zero-fills every row of the surface's pixel
   buffer using the row pitch. */
extern "C" {
void *memset(void *dest, int value, unsigned int count);
}

struct Surface {
    char pad[0x1a];
    unsigned short width;
    unsigned short height;
    int pitch;
    char pad2[4];
    void *bits;

    void ClearRows();
};

void Surface::ClearRows()
{
    char *row;
    int y;

    if (bits == 0)
        return;
    row = (char *)bits;
    for (y = 0; y < height; y++) {
        memset(row, 0, width * 2);
        row += pitch * 2;
    }
}
