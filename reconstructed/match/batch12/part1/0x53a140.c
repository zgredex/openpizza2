/* Gfx_BuildBlendTable: builds the 16x64 blending table (0x53a140). */
extern "C" int __fastcall Gfx_BuildBlendTable(int *table)
{
    int i;
    int j;

    for (i = 0; i < 0x10; i++) {
        for (j = -0x1f; j < 0x20; j++) {
            table[(j + 0x1f) | (i << 6)] = (int)((double)j * (double)i / 15.0);
        }
    }
    return (int)table;
}
