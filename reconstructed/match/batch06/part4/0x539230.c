/* Surface_Release: releases the surface's attached display buffer when it is
   still locked (0x539230).  Build: /O2 /TP. */
struct Surface {
    char pad[0x28];
    int field28;
    int field2c;
    char pad2[0x10];
    int field40;
    void Release();
};

void Surface::Release()
{
    if (field2c > 0) {
        int *target;

        field28 = 0;
        target = *(int **)(field40 + 0xc);
        (*(void (__stdcall **)(int *, int))(*target + 0x80))(target, 0);
        field2c = 0;
    }
}
