unsigned Sound_AlignBufferSize(double scale, int object)
{
    unsigned int value = (unsigned int)((double)*(unsigned int *)(object + 8) * scale);
    unsigned short alignment = *(unsigned short *)(object + 0xc);

    if (alignment >= 2) {
        int rem = value % alignment;
        if (rem != 0) {
            value -= rem;
        }
    } else {
        if ((value & 1) != 0) {
            value -= value & 1;
        }
    }
    return value;
}
