/* Rating_AdjustB: rating plus two points per hour past 0x32 (0x4d3fe0). */
int __fastcall Rating_AdjustB(int *rating)
{
    int value = rating[4];

    if (rating[0xe] > 0x32)
        value += (0x32 - rating[0xe]) * 2;
    if (value < 0)
        value = 0;
    return value;
}
