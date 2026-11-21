/* Math_PiecewiseLinear: two-segment linear mapping used by the rating
   curves (0x50fbe0). */
int __stdcall Math_PiecewiseLinear(int value)
{
    int result;

    if (value >= 0x32)
        result = (value - 0x32) * 0x20 / 0x19 + 0x24;
    else
        result = value * 0x12 / 0x19;
    return result;
}
