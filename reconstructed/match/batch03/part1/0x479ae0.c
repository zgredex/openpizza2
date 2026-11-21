/* Game_ComputeCityConditionScore: stores category 5's average in a byte field (0x479ae0). */
__int64 __fastcall Game_ComputeAverageCategoryValue(void *this_, int unused,
                                                   int category);

void __fastcall Game_ComputeCityConditionScore(void *this_, int unused)
{
    *(unsigned int *)((char *)this_ + 0x1870) =
        (unsigned char)Game_ComputeAverageCategoryValue(this_, unused, 5);
}
