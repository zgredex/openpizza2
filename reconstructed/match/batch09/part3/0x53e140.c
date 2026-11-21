/* Surface_SetPixel: plots a 16-bit pixel when it lies inside the surface
   bounds (0x53e140). */
void Surface_SetPixel(int surface, int x, int y, unsigned short color)
{
    if (x >= 0 && x < (int)*(unsigned short *)(surface + 0x1a) &&
        y >= 0 && y < (int)*(unsigned short *)(surface + 0x1c)) {
        *(unsigned short *)(*(int *)(surface + 0x20) * y +
                            *(int *)(surface + 0x28) + x * 3) = color;
    }
}
