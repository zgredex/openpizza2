/* Array_AreBothCountsPositive (0x512700, 48 bytes).  Build: /O2 /TP.
   Tests the two indexed counters, both of which must be positive. */
struct Array {
    int AreBothCountsPositive(int first, int second);
};

int Array::AreBothCountsPositive(int first, int second)
{
    if (*(int *)((char *)this + (first & 0xff) * 4 + 0x64) <= 0 ||
        *(int *)((char *)this + (second & 0xff) * 4 + 0x64) <= 0)
        return 0;
    return 1;
}
