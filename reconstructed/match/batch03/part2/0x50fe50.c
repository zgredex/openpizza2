/* Game_CountActiveStats - 0x50fe50, 23 bytes */
int __fastcall Game_CountActiveStats(void *this_)
{
    int count = 0;
    int *value = (int *)((char *)this_ + 0x64);
    int remaining = 0x56;

    do
    {
        if (*value > 0)
            count++;
        value++;
        remaining--;
    } while (remaining != 0);

    return count;
}
