/* Object_SumFloat25: sums 25 floats starting at offset 0x78 (0x401170). */
float __fastcall Object_SumFloat25(char *this_)
{
    float *value = (float *)(this_ + 0x78);
    float total = *(float *)0x55c2e4;
    int count = 0x19;

    do {
        total += *value;
        value++;
    } while (--count);
    return total;
}
