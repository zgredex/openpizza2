/* Building_GetAreaByLevel: returns the building area for a level
   (0x48d020). */
float __stdcall Building_GetAreaByLevel(int level)
{
    switch (level) {
    case 3:
        return *(float *)0x55c49c;
    case 2:
        return *(float *)0x55c498;
    case 1:
        return *(float *)0x55c494;
    case 0:
        return *(float *)0x55c490;
    default:
        return *(float *)0x55c2e4;
    }
}
