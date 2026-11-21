/* Rating_AdjustA: rating plus three points per hour past 0x37 (0x4d3fc0). */
int __fastcall Rating_AdjustA(int *rating)
{
    int value = rating[2];

    if (rating[0xe] > 0x37)
        value += (0x37 - rating[0xe]) * 3;
    if (value < 0)
        value = 0;
    return value;
}
