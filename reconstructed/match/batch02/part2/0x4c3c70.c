/* Lookup_BytePlusOne - 0x4c3c70, 18 bytes */
extern int DAT_0057d73c[];

int Lookup_BytePlusOne(int index)
{
    if (index == 0)
        return 0;
    return DAT_0057d73c[index] + 1;
}
