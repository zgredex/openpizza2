/* Math_RoundFloat: rounds a float to the nearest integer, halves away from
   zero (0x403850).  Build: /O2. */
extern float DAT_0055c2e4;
extern double DAT_0055c300;

long Math_RoundFloat(float value)
{
    if (value >= DAT_0055c2e4)
        return (long)(value + DAT_0055c300);
    return (long)(value - DAT_0055c300);
}
