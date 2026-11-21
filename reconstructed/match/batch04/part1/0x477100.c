/* Clamp_0_100: clamps a value in place to the 0..100 range (0x477100). */
void __stdcall Clamp_0_100(int *value)
{
    if (*value > 100)
        *value = 100;
    if (*value < 0)
        *value = 0;
}
