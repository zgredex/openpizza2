/* Rating_GetComposite (0x4d4000). */
struct Rating {
    char pad0[0xc];
    int value;              /* 0x0c */

    int ClampAdjusted();
    int AdjustA();
    int AdjustB();
    int HasFlags();
    int GetComposite();
};

int Rating::GetComposite()
{
    int clamped = ClampAdjusted();
    int adjustedA = AdjustA();
    int value = this->value;
    int adjustedB = AdjustB();
    int average = (value + adjustedB + adjustedA + clamped) >> 2;

    if (clamped >= adjustedA)
        clamped = adjustedA;
    if (clamped >= adjustedB)
        clamped = adjustedB;
    if (clamped >= value)
        clamped = value;
    if ((char)HasFlags() != 0)
        average = (average - (average >> 31)) >> 1;
    return average <= clamped * 4 ? average : clamped * 4;
}
