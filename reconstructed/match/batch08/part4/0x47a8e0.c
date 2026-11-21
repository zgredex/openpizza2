/* Matrix_Max4x9: computes the maximum over a 4x9 matrix of ints
   (0x47a8e0). */
int __fastcall Matrix_Max4x9(void *self)
{
    int maximum = 0;
    int *value = (int *)((char *)self + 0x13f4);
    int n = 9;

    do {
        if (value[-0x12] > maximum)
            maximum = value[-0x12];
        if (value[0] > maximum)
            maximum = value[0];
        if (value[0x12] > maximum)
            maximum = value[0x12];
        if (value[0x24] > maximum)
            maximum = value[0x24];
        value++;
        n--;
    } while (n != 0);
    return maximum;
}
