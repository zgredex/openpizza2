/* Rect_Center: shifts a rectangle's origin so the global rect is centered on
   it (0x4f3490).  Build: /O2. */
void __stdcall Rect_Center(int *x, int *y)
{
    int centerX = *(int *)0x571950;
    int centerY = *(int *)0x571954;

    *x = *x - (centerX >> 1);
    *y = *y - (centerY >> 1);
}
