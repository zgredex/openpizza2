/* Rating_GetInverse100: 100 minus three times a rating, clamped at zero (0x4781b0). */
int __fastcall Rating_GetInverse100(char *this_)
{
    int value = 100 - *(int *)(this_ + 0x19f4) * 3;

    if (value < 0)
        value = 0;
    return value;
}
