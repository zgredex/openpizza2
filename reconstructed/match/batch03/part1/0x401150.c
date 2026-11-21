/* Record_SumFloatArray26: sums 26 floats starting at offset 0x10 (0x401150). */
float __fastcall Record_SumFloatArray26(char *this_)
{
    float *value = (float *)(this_ + 0x10);
    float total = *(float *)0x55c2e4;
    int count = 0x1a;

    do {
        total += *value;
        value++;
    } while (--count);
    return total;
}
