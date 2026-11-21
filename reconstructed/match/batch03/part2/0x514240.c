/* Array_CountNonZero20 - 0x514240, 23 bytes */
int __fastcall Array_CountNonZero20(void *this_)
{
    int count = 0;
    int *value = (int *)((char *)this_ + 0x60);
    int remaining = 0x14;

    do
    {
        if (*value != 0)
            count++;
        value += 3;
        remaining--;
    } while (remaining != 0);

    return count;
}
