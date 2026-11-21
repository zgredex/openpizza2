/* Array_CountValid8: counts the eight shorts at +0x14 that are not -1 (0x4edbd0). */
int __stdcall Array_CountValid8(char *array)
{
    int count = 0;
    short *slot = (short *)(array + 0x14);
    int remaining = 8;

    do {
        if (*slot != -1) {
            count++;
        }
        slot++;
        remaining--;
    } while (remaining != 0);
    return count;
}
