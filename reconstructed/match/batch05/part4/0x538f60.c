/* Surface_LockAndMark: locks the surface and marks it dirty (0x538f60). */
struct Surface {
    char pad[0x2c];
    int dirty;
    int Lock(int a, int b);
    int LockAndMark();
};

int Surface::LockAndMark()
{
    if (Lock(1, 1) != 0) {
        dirty = 1;
        return 1;
    }
    return 0;
}
