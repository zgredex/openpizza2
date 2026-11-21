/* Math_TruncateDouble: scales a value by a percentage and clamps it to
   [minimum, value] before converting to int (0x511fa0). */
extern "C" int __stdcall Math_TruncateDouble(int value, int amount)
{
    float original = (float)value;
    float result = original * *(float *)0x55c430;
    int factor = 100 - amount;

    result = result * factor;
    if (result < *(float *)0x55c470)
        result = *(float *)0x55c470;
    if (result > original)
        result = original;
    return (int)result;
}
