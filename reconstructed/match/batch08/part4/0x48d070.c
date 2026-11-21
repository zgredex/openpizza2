/* Stats_GetAmountByType: returns the amount for a statistics type
   (0x48d070). */
float __stdcall Stats_GetAmountByType(int type)
{
    switch (type) {
    case 3:
        return *(float *)0x55c4ac;
    case 2:
        return *(float *)0x55c4a8;
    case 1:
        return *(float *)0x55c4a4;
    case 0:
        return *(float *)0x55c4a0;
    default:
        return *(float *)0x55c2e4;
    }
}
